#include <REGX52.H>
#include "Delay.h"

void Delay_ms (unsigned int t)
{
	unsigned int x, y;
	for (x = 0; x < t; x++)
	{
		for (y = 0; y < 123; y++);
	}
}

void delay_short() {
    unsigned char i;
    for (i = 0; i < 4; i++) {}
}

void delay(unsigned int time) {
    TMOD = 0x01;
    while (time--) {
        TH0 = -1000 / 256;
        TL0 = -1000 % 256;
        TR0 = 1;
        while (!TF0);
        TR0 = 0;
        TF0 = 0;
    }
}