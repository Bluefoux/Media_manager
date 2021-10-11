#include "../include/Time.hpp"

Time::Time(int minutes, int seconds): time(std::chrono::minutes(minutes) + std::chrono::seconds(seconds)) {}
Time::Time(int seconds) : time(std::chrono::seconds(seconds)) {}
Time::Time(std::chrono::duration<int64_t> time) : time(time) {}

bool Time::operator==(const Time& rhs) const
{
    bool tmpoperator = (time == rhs.getChronoTime());
    return tmpoperator;
}

std::chrono::duration<int64_t> Time::getChronoTime() const { return time; }