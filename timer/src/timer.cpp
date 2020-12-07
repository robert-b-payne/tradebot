#include "timer.hpp"
// #include <map>
// #include <pthread.h>
// #include <unistd.h>
// #include <iostream>
// #include <functional>

// using namespace std;

// class Data
// {
// public:
//     Data()
//     {
//         std::cout << "data created!" << std::endl;
//     }
//     ~Data()
//     {
//         std::cout << "data destroyed!" << std::endl;
//     }
//     function<void()> func;
//     int delay;
//     Timer *this_;
//     pthread_t t;
//     int iterations;
// };

// Timer::Timer() {}

// pthread_t Timer::setTimeout(function<void()> f, int delay)
// {
//     Data *d = new Data();
//     d->func = f;
//     d->delay = delay;
//     pthread_t t;
//     pthread_create(&t, NULL, [](void *x) -> void * {
//         Data *y = (Data *)x;
//         usleep(y->delay * 1000);
//         y->func();
//         delete y;
//         pthread_exit(NULL);
//     },
//                    (void *)d);
//     return t;
// }

// void Timer::clearTimeout(pthread_t t)
// {
//     cout << "Clearing timeout . . . " << endl;
//     pthread_cancel(t);
// }

// pthread_t Timer::setInterval(function<void()> f, int delay, int iterations)
// {
    
//     Data *d = new Data();
//     d->func = f;
//     d->delay = delay;
//     d->this_ = this;
//     d->iterations=iterations;
//     pthread_t t;
//     pthread_create(&t, NULL, [](void *x) -> void * {
//         // int i = 1;
//         Data *dataPtr = (Data *)x;
//         int iterationCount=0;
//         if(dataPtr->iterations <0) iterationCount = dataPtr->iterations - 1;
//         while (iterationCount < dataPtr->iterations)
//         {
//             usleep(dataPtr->delay * 1000);
//             // cout << i++ << " ";
//             dataPtr->func();
//             if(dataPtr->iterations >= 0) iterationCount++;
//         }
//         delete dataPtr;
//         pthread_exit(NULL);
//     },
//                    (void *)d);
//     return t;
// }

// void Timer::clearInterval(pthread_t t)
// {
//     cout << "Clearing interval . . . " << endl;
//     pthread_cancel(t);
// }

Timer::Timer()
{
    std::cout << "created timer!" << std::endl;
}

Timer::~Timer()
{
    std::cout << "timer destroyed!" << std::endl;
}

std::thread Timer::setTimeout(void (*callback)(void) /*, uint32_t delay*/)
{
    // auto callback = [](std::function<void()> func, uint32_t delay){
    //     usleep(1000 * delay);
    //     func();
    // };
    // auto callback = [](/*std::function<void()> func, uint32_t delay*/){
    //     // usleep(1000 * delay);
    //     std::cout << "inside another thread!" << std::endl;
    // };



    // std::thread threadObj(func, func, delay);
    std::cout << "1" << std::endl;
    callback();
    std::thread threadObj(callback);
    return threadObj;
}