#include "Scheduler.h"

void Scheduler::addProcess(const Process& p)
{ 
    processes.push_back(p);
}

void Scheduler::schedule()
{ // 按到达时间排序
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
        }
    );

    int currentTime = 0;
    for (auto& p : processes) {
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }
        p.startTime = currentTime;
        p.finishTime = currentTime + p.serviceTime;
        currentTime = p.finishTime;
    }
}

void Scheduler::printSchedule() const
{ std::cout << "Process ID\tArrival Time\tService Time\tStart Time\tFinish Time" << std::endl;
    for (const auto& p : processes) {
        std::cout << p.id << "\t\t" << p.arrivalTime << "\t\t" << p.serviceTime << "\t\t"
            << p.startTime << "\t\t" << p.finishTime << std::endl;
    }
}
