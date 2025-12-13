#include <REGX52.H>
#include <.\ThuVien\Delay.h>
#define LED_P0 P0
#define LED_P3 P3
sbit Start = P1^0;
sbit Stop = P1^1;
//	
unsigned char Delay1SvaQuetPhim(){
	unsigned char i;
	for (i=0; i<100; i++) {
		Delay_ms(10);			
		if (Stop == 0) {
			LED_P0 = 0x00;
			LED_P3 = 0x00;
			return 1;
		}
	}
	return 0;
}
//	
void main() {
	LED_P0 = 0x00;
	LED_P3 = 0x00;
	while(1) {	// while(1)_1
		if (Start == 0) {	// if_1
			while(1) {	// while(1)_2
				LED_P0 = ~LED_P0;
				LED_P3 = ~LED_P3;
				if (Delay1SvaQuetPhim() ){	// if_2
					break;
				}
			}
		}
	}
}
