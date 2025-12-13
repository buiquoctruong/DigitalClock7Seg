#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\dichNoiTiep.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

unsigned char giay = 0;
unsigned int dem = 0;

void Timer0_Init() {
	TMOD |= 0x01;
	TH0 = 0x3C;
	TL0 = 0xB0;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void Timer0_ISR() interrupt 1 {
	TH0 = 0x3C;
	TL0 = 0xB0;
	dem++;
}

void main() {
	P1 = 0;
	Timer0_Init();
	while (1) {
		unsigned char dvi;
		dvi = giay % 10;
		dichNoiTiep(Code7Seg[dvi]);
		led6 = 1; Delay_ms(2);
		led6 = 0;
		
		if (dem >= 20) {
			dem = 0;
			giay++;
			if (giay == 60) {
				giay = 0;
			}
		}
	}
}
