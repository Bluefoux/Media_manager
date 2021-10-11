#include "../include/Track.hpp"

Track::Track(const std::string& name, const Time& length): name(name), length(length) {}

//Track class functions
const std::string& Track::getName() const {return name;}
const Time& Track::getLength() const{return length;}

bool Track::operator==(const Track& trackes) const
{
    bool tmpoperator = ((name == trackes.getName()) && (length == trackes.getLength()));
    return tmpoperator;
}