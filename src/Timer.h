#ifndef TIMER
#define TIMER

#include <sys/time.h>

class Timer {

public:

    void StartTimer();
    double EndTimer();

private:

    double startTime, endTime;
    struct timeval startTimeVal, endTimeVal;

};

#endif

