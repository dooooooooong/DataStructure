 // On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___


struct Clock {
    int hr, min, sec;
};

using pClock = Clock*;

void tick(pClock clk);
void show(pClock clk, char end = '\n');
void runs(pClock clk, char end = '\n');

