// #include <pthread.h>
// #include <map>
#include <functional>
#include <thread>
#include <unistd.h>

// #ifndef TIMER_HPP
// #define TIMER_HPP

// class Timer
// {
// public:
//     Timer();
//     pthread_t setTimeout(std::function<void()>, int);
//     pthread_t setInterval(std::function<void()>, int, int iterations=-1);
//     void clearInterval(pthread_t t);
//     void clearTimeout(pthread_t);
// };

// #endif


#include <iostream>
#include <thread>

class Timer
{
public:
    Timer();
    ~Timer();
    std::thread setTimeout(void (*f)(void)/*, uint32_t delay*/);
private:
};