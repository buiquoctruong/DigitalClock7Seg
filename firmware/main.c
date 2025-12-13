#include <REGX52.H>
#include ".\ThuVien\Delay.h"	
#define LED_PORT P0
void main(){
	unsigned char i;
	unsigned int t;
	while (1){
		t = 500;
		for (i = 0; i < 5; i++) {
			LED_PORT = 0x00; 	Delay_ms(t);
			LED_PORT = ~P0; 	Delay_ms(t);
		}
		for (i = 0; i < 5; i++) {
			LED_PORT = 0xAA;	Delay_ms(t);
			LED_PORT = ~P0; 	Delay_ms(t);
		}
	}
}
