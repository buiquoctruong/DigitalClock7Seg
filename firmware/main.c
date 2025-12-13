#include <REGX52.H>
#include ".\ThuVien\Delay.h"	
#define LED_PORT P0
void main(){
		unsigned int t;
		while (1){
		t = 500;
		LED_PORT = 0xFF;	Delay_ms(t);
		LED_PORT = 0xFE; 	Delay_ms(t);
		LED_PORT = 0xFC; 	Delay_ms(t);
		LED_PORT = 0xF8; 	Delay_ms(t);
		LED_PORT = 0xF0; 	Delay_ms(t);
		LED_PORT = 0xE0; 	Delay_ms(t);
		LED_PORT = 0xC0; 	Delay_ms(t);
		LED_PORT = 0x80; 	Delay_ms(t);
		LED_PORT = 0x00; 	Delay_ms(t);
	}
}
