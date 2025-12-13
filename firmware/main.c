#include <regx52.h>
#include ".\ThuVien\Delay.h"
unsigned char code maLED7[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define abcdefg P3
sbit led1 = P1^2;
sbit led2 = P1^3;
sbit led3 = P1^4;
sbit led4 = P1^5;
sbit led5 = P1^6;
sbit led6 = P1^7;
void main(){	
	unsigned char gio, phut, giay;
	unsigned char chuc, dvi;
	unsigned char i;
	gio = phut = giay = 0;
	while(1){
		for(i=0;i<166;i++){
			chuc = gio/10;
			dvi = gio%10;
			abcdefg = maLED7[chuc];
			led1 = 1; Delay_ms(2);
			led1 = 0;		
			abcdefg = maLED7[dvi];
			led2 = 1; Delay_ms(2);
			led2 = 0;

			chuc = phut/10;
			dvi = phut%10;
			abcdefg = maLED7[chuc];
			led3 = 1; Delay_ms(2);
			led3 = 0;		
			abcdefg = maLED7[dvi];
			led4 = 1; Delay_ms(2);
			led4 = 0;

			chuc = giay/10;
			dvi = giay%10;
			abcdefg = maLED7[chuc];
			led5 = 1; Delay_ms(2);
			led5 = 0;		
			abcdefg = maLED7[dvi];
			led6 = 1; Delay_ms(2);
			led6 = 0;
		}
		giay++;
		if(giay == 60){
			giay = 0;			
			phut++;
			if(phut == 60){
				phut = 0;
				gio++;
				if(gio == 24){
					gio = 0;
				}
			}
		}
	}
}
