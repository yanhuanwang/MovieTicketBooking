# Use a specific stable version of Ubuntu as the base image
FROM ubuntu:20.04

# Set environment variables to non-interactive to avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Update package list and install basic dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    git \
    curl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Install Boost libraries separately to handle dependencies properly
RUN apt-get update && \
    apt-get install -y \
    libboost-all-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create a directory for the application
WORKDIR /app

# Copy the source code to the container
COPY . .

# Build the application
RUN mkdir build
WORKDIR /app/build
RUN cmake ..
RUN make

# Expose the port that the application will run on
EXPOSE 8080

# Run the application
CMD ["./MovieTicketBooking"]
