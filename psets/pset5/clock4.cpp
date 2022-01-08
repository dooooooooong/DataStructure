 // On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___

#include <iostream>
#include <iomanip>
#include <unistd.h>

struct Clock {
    int hr, min, sec;
};

using pClock = Clock*;

void tick (pClock ptr);
void show (pClock ptr);
void runs (pClock ptr);

int main (void) {
    pClock ptr = new Clock {11, 58, 56};

    runs(ptr);

    return 0;
}

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

void show (pClock ptr) {
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":"
              << std::setw(2) << ptr->min << ":"
              << std::setw(2) << ptr->sec << "\r";
}

void runs (pClock clk) {
    while (true) {
        sleep(1);
        tick(clk);
        show(clk);
    }
}