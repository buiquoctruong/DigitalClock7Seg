#include <regx52.h>
#include ".\ThuVien\Delay.h"
unsigned char code maLED7[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char dem;
unsigned char chuc, dvi;
#define abcdefg P3
sbit led1 = P1^2;
sbit led2 = P1^3;
void main(){
	P1 = 0;
	dem = 23;
	chuc = dem/10;
	dvi = dem%10;
	while(1){
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
