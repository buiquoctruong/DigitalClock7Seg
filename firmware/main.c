#include <regx52.h>
#include ".\ThuVien\Delay.h"
unsigned char code maLED7[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define abcdefg P3
sbit led1 = P1^2;
sbit led2 = P1^3;
void main(){	
	unsigned char dem;
	unsigned char chuc, dvi;
	unsigned int i;
	while(1){
		P1 = 0;
		for (dem=0; dem<100; dem++){
			chuc = dem/10;
			dvi = dem%10;
			for (i=0; i<100; i++){
				abcdefg = maLED7[chuc];
				led1 = 1;
				Delay_ms(2);
				led1 = 0;
				abcdefg = maLED7[dvi];
				led2 = 1;
				Delay_ms(2);
				led2 = 0;
			}
		}
	}
}
