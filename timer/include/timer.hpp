#include <pthread.h>
#include <map>
#include <functional>

#ifndef TIMER_HPP
#define TIMER_HPP

class Timer
{
public:
    Timer();
    pthread_t setTimeout(std::function<void()>, int);
    pthread_t setInterval(std::function<void()>, int, int iterations=-1);
    void clearInterval(pthread_t t);
    void clearTimeout(pthread_t);
};

#endif
