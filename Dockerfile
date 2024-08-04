# Stage 1: Build stage
FROM ubuntu:20.04 as builder

# Set environment variables to non-interactive to avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Update package list and install build dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    libboost-all-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Create a directory for the application
WORKDIR /app

# Copy the source code to the container
COPY . .

# Build the application
RUN rm -rf build/
RUN mkdir build && cd build && cmake .. && make

# Stage 2: Runtime stage
FROM ubuntu:20.04

# Set environment variables to non-interactive to avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install runtime dependencies
RUN apt-get update && \
    apt-get install -y \
    libboost-system1.71.0 \
    libboost-thread1.71.0 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Copy the built application and necessary files from the builder stage
COPY --from=builder /app/build/MovieTicketBooking /usr/local/bin/MovieTicketBooking
COPY --from=builder /app/build/swagger-ui /usr/local/swagger-ui

WORKDIR /usr/local/

# Expose the port that the application will run on
EXPOSE 8080

# Run the application
CMD ["MovieTicketBooking"]
