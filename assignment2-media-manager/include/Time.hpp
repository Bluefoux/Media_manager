#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>

class Time {
 public:
    Time(int minutes, int seconds);
    Time(int seconds);
    Time(std::chrono::duration<int64_t> time);
   ~Time(){};
    bool operator==(const Time& rhs) const;

    std::chrono::duration<int64_t> getChronoTime() const;

 private:
    std::chrono::duration<int64_t> time;
};
#endif // TIME_HPP