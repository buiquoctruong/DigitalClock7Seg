#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\dichNoiTiep.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

unsigned char gio, phut, giay;
unsigned int dem = 0;

void Timer0_khoiTao() {
	TMOD |= 0x01;
	TH0 = 0x3C; TL0 = 0xB0;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}
void Timer0_ISR() interrupt 1 {
	TH0 = 0x3C; TL0 = 0xB0;
	dem++;
}

void HienThi() {
	unsigned char chuc, dvi;
	chuc = gio / 10;
	dvi = gio % 10;
	dichNoiTiep(Code7Seg[chuc]);
	led1 = 1; Delay_ms(1); 
	led1 = 0;
	dichNoiTiep(Code7Seg[dvi]);
	led2 = 1; Delay_ms(1); 
	led2 = 0;
	chuc = phut / 10;
	dvi = phut % 10;
	dichNoiTiep(Code7Seg[chuc]);
	led3 = 1; Delay_ms(1); 
	led3 = 0;
	dichNoiTiep(Code7Seg[dvi]);
	led4 = 1; Delay_ms(1); 
	led4 = 0;
	chuc = giay / 10;
	dvi = giay % 10;
	dichNoiTiep(Code7Seg[chuc]);
	led5 = 1; Delay_ms(1); 	
	led5 = 0;
	dichNoiTiep(Code7Seg[dvi]);
	led6 = 1; Delay_ms(1); 
	led6 = 0;
}

void main() {
	gio = phut = giay = 0;
	Timer0_khoiTao();
	while (1) {
		HienThi();
		if (dem >= 20) { //20
			dem = 0;
			giay++;
			if (giay == 60) {
				giay = 0;
				phut++;
				if (phut == 60) {
					phut = 0;
					gio++;
					if (gio == 24) {
						gio = 0;
					}
				}
			}
		}
	}
}
