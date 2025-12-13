#include <REGX52.H>
#include ".\ThuVien\Delay.h"
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define LED7Chuc P2
#define LED7Dvi P3
sbit LEDDo = P0^0;
sbit LEDVang = P0^1;
sbit LEDXanh = P0^2;
void main(){
	signed char i;
	while(1){
		LEDDo = 0;
		LEDXanh = 1;
		LEDVang = 1;
		for (i=20; i>=0; i--){ 
			LED7Chuc = Code7Seg[i/10];
			LED7Dvi = Code7Seg[i%10];
			Delay_ms(1000);
		}
		LEDDo = 1;
		LEDXanh = 0;
		LEDVang = 1;
		for (i=15; i>=0; i--){
			LED7Chuc = Code7Seg[i/10];
			LED7Dvi = Code7Seg[i%10];
			Delay_ms(1000);
		}
		LEDDo = 1;
		LEDXanh = 1;
		LEDVang = 0;
		for (i=5; i>=0; i--){
			LED7Chuc = Code7Seg[i/10];
			LED7Dvi = Code7Seg[i%10];
			Delay_ms(1000);
		}
	}
}
