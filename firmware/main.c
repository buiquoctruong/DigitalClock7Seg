#include <REGX52.H>
#include <.\ThuVien\Delay.h>
sbit LED = P3^0;
sbit ON = P1^0;
sbit OFF = P1^1;
void main() {
	P0 = P3 = 0;
	LED = 0;
	while (1) {
		if (ON == 0) {
			Delay_ms(20);
			if (ON == 0) {
				LED = 1;
			}
		}
		if (OFF == 0) {
			Delay_ms(20);
			if (OFF== 0) {
				LED = 0;
			}
		}
	}
}
