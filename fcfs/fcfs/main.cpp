#include"Scheduler.h"
int main() {
    Scheduler scheduler;
    scheduler.addProcess(Process(1, 0, 5));
    scheduler.addProcess(Process(2, 6, 3));
    scheduler.addProcess(Process(3, 9, 8));
    scheduler.addProcess(Process(4, 8, 6));

    scheduler.schedule();
    scheduler.printSchedule();

    return 0;
}
