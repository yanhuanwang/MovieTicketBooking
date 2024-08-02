#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie {
public:
    Movie(const std::string& name);

    std::string getName() const;

private:
    std::string name;
};

#endif // MOVIE_H
