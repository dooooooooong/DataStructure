struct Clock {
    int hr, min, sec;
};

using pClock = Clock*;

void tick(pClock clk);
void show(pClock clk, char end = '\n');
void runs(pClock clk, char end = '\n');

