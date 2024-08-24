#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"process.h"
class Scheduler {
public:
    std::vector<Process> processes;

    void addProcess(const Process& p);
    void schedule();
    void printSchedule() const;
};
