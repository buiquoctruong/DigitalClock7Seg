#include <REGX52.H>
#include ".\ThuVien\Delay.h"
void main (){
	unsigned char i;
	unsigned int t;
	while (1){
		t = 500;
		for (i = 0; i < 5; i++) {
			P0 = 0x00; Delay_ms(t);
			P0 = 0xFF; Delay_ms(t);
		}
		for (i = 0; i < 5; i++) {
			P0 = 0x0F; Delay_ms(t);
			P0 = 0xF0; Delay_ms(t);
		}
		for (i=0; i < 5;i++) {
			P0 = 0x55; Delay_ms(t);
			P0 = 0xAA; Delay_ms(t);
		}
	}
}
