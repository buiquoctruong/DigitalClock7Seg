#include <REGX52.H>
#include <.\ThuVien\Delay.h>
#define LED_P0 P0
#define LED_P3 P3
sbit Start = P1^0;
sbit Stop = P1^1;
void main() {
	LED_P0 = 0xFF;
	LED_P3 = 0xFF;
	while(1) {
		if (Start == 0){
			while(1) {
				LED_P0 = ~LED_P0;
				LED_P3 = ~LED_P3;
				Delay_ms(500);
				if (Stop == 0){
					LED_P0 = 0x00;
					LED_P3 = 0x00;
					break;
				}
			}
		}
	}
}
