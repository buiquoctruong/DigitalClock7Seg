#include <REGX52.H>
#include <.\ThuVien\Delay.h>
#define LED_PORT0 P0
#define LED_PORT3 P3
unsigned char i;
void main(){
	LED_PORT0 = 0x00;
	LED_PORT3 = 0x00; 
	Delay_ms(500);
	while(1){	
		LED_PORT0 = 0x01;
		Delay_ms(500);
		for(i=0; i<8; i++){
			LED_PORT0 = LED_PORT0 << 1;
			Delay_ms(500);
		}
		LED_PORT3 = 0x01;
		Delay_ms(500);
		for(i=0; i<8; i++){
			LED_PORT3 = LED_PORT3 << 1;
			Delay_ms(500);
		}
	}
}
