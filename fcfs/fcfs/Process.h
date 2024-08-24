#pragma once
#define  N  5
class Process
{
public:
    int id;
    int arrivalTime;
    int serviceTime;
    int startTime;
    int finishTime;
    Process(int id, int arrivalTime, int serviceTime)
        : id(id), arrivalTime(arrivalTime), serviceTime(serviceTime), startTime(-1), finishTime(-1) {}
};

