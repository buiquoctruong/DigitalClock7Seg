#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\dichNoiTiep.h"
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main(){	
	unsigned char gio, phut, giay;
	unsigned char chuc, dvi;
	unsigned char i;
	gio = phut = giay = 0;
	while(1){
		for (i=0;i<166;i++){ //166
			chuc = gio/10;
			dvi = gio%10;
			dichNoiTiep (Code7Seg[chuc]); 
			led1 = 1;	Delay_ms(1);	
			led1 = 0;
			dichNoiTiep (Code7Seg[dvi]);
			led2 = 1; Delay_ms(1);
			led2 = 0;
						
			chuc = phut/10;
			dvi = phut%10;
			dichNoiTiep (Code7Seg[chuc]); 
			led3 = 1; Delay_ms(1);
			led3 = 0;			
			dichNoiTiep (Code7Seg[dvi]); 
			led4 = 1; Delay_ms(1);
			led4 = 0;
			
			chuc = giay/10;
			dvi = giay%10;
			dichNoiTiep (Code7Seg[chuc]);
			led5 = 1; Delay_ms(1);
			led5 = 0;
			dichNoiTiep (Code7Seg[dvi]);
			led6 = 1; Delay_ms(1);
			led6 = 0;
		}
		giay++;
		if (giay == 60){
			giay = 0;			
			phut++;
			if (phut == 60){
				phut = 0;
				gio++;
				if (gio == 24){
				gio = 0;
				}
			}
		}
	}
}
