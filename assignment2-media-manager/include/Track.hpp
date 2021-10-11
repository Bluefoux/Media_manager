#ifndef TRACK_HPP
#define TRACK_HPP

#include <string>
#include "Time.hpp"

class Track
{
    private:
        std::string name;
        Time length;
    public:
        Track(const std::string& name, const Time& length);
        const std::string& getName() const;
        const Time& getLength() const;
        ~Track(){};
        bool operator==(const Track& trackes) const;
};
#endif //TRACK_HPP