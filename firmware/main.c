#include <regx52.h>
#include ".\ThuVien\Delay.h"
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

// Khai bao ket noi
sbit DS = P3^0;
sbit SHCP = P3^3;	
sbit STCP = P3^2;	

unsigned char Data; 
unsigned char i;	
unsigned char MatNaBit; 
unsigned char GiaTriBit; 

void main(){
	Data = Code7Seg[2];
	P0 = Data;		
	for (i=0; i<8; i++){
		MatNaBit = 0x80>>i;	
		GiaTriBit = Data&MatNaBit;
		DS = GiaTriBit ? 1 : 0; 
		// Xung dich du lieu
		SHCP = 0;
		SHCP = 1;
	}
	// xung chot du lieu
	STCP = 0;
	STCP = 1;
	while(1);
}
