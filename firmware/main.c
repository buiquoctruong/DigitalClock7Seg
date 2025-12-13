#include <regx52.h>
#include ".\ThuVien\Delay.h"
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

sbit DS = P3^0;
sbit SHCP = P3^3;	
sbit STCP = P3^2;	
	
void DichNoiTiep (unsigned char Data){
	unsigned char i;	
	for (i=0; i<8; i++){
		DS = Data&(0x80>>i) ? 1 : 0; 
		SHCP = 0; SHCP = 1;
	}
	STCP = 0; STCP = 1;
}

void main(){	
	unsigned char so=0;
	while(1){
		P0 = Code7Seg[so];
		DichNoiTiep (Code7Seg[so]);
		Delay_ms(500);
		so++;
		if (so == 9){
			so = 0;	
		}
	}
}
