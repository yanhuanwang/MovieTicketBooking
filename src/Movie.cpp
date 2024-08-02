#include "Movie.h"

Movie::Movie(const std::string& name) : name(name) {}

std::string Movie::getName() const {
    return name;
}
