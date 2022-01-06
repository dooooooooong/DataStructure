#include <iostream>
#include <iomanip>
#include <unistd.h>

#include "clock.h"

void tick(pClock ptr) {
    ptr->sec++;

    if (ptr->sec >= 60) {
        ptr->sec -=60;
        ptr->min++;
    }

    if (ptr->min >= 60) {
        ptr->min -=60;
        ptr->hr++;
    }
    
    if (ptr->hr >= 24) ptr->hr = 0;
}

void show (pClock ptr, char end) {
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":"
              << std::setw(2) << ptr->min << ":"
              << std::setw(2) << ptr->sec << end;
}

void runs (pClock clk, char end) {
    while (true) {
        sleep(1);
        tick(clk);
        show(clk, end);
    }
}