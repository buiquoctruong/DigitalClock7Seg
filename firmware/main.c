#include <REGX52.H>
#include <.\ThuVien\Delay.h>
sbit LED_PIN = P0^0;
void main () {
	P0 = 0;
	P3 = 0;
	LED_PIN = 0;
	while(1){
		LED_PIN = !LED_PIN;
		Delay_ms(500);
	}
}
