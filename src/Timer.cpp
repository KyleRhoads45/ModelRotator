#include "Timer.h"

void Timer::StartTimer() {
    gettimeofday(&startTimeVal, NULL);
}

double Timer::EndTimer() {
    gettimeofday(&endTimeVal, NULL);
    startTime = startTimeVal.tv_sec + (startTimeVal.tv_usec / 1000000.0);
    endTime = endTimeVal.tv_sec + (endTimeVal.tv_usec / 1000000.0);
    return (endTime - startTime);
}