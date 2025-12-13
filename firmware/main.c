#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\dichNoiTiep.h"
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

sbit Chuc	= P1^2;
sbit Dvi 	= P1^3;

void main(){	
	unsigned char chuc, dvi;
	unsigned char i, so;
	P1 = 0;
	while(1){
		for (i=0;i<166;i++){ 
			chuc = so/10;
			dvi = so%10;
			
			dichNoiTiep (Code7Seg[chuc]); 
			Chuc = 1; Delay_ms(2);	
			Chuc = 0;
			dichNoiTiep (Code7Seg[dvi]);
			Dvi = 1; Delay_ms(2);
			Dvi = 0;
		}

		so++;
		if (so == 60){
			so = 0;	
		}
	}
}
