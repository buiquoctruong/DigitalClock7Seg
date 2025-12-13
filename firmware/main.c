#include <REGX52.H>
#include ".\ThuVien\Delay.h"	
#define LED_PORT P0
unsigned char i;
//	
void LEDSangLanDanTraiPhai (){
	unsigned char M[ ] = {0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00};
	LED_PORT = 0xFF;	
	Delay_ms(100);
	for (i = 0; i < 8; i++) {
    	LED_PORT = M[i];
		Delay_ms(100);
  }
}

//	
void LEDSangLanDanPhaiTrai (){
	unsigned char N[ ] = {0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00};
	LED_PORT = 0xFF;	
	Delay_ms(100);
	for (i = 0; i < 8; i++) {
    LED_PORT = N[i];	
		Delay_ms(100);
  }
}

void main(){
	while(1){
		LEDSangLanDanTraiPhai();
		LEDSangLanDanPhaiTrai();
	}
}
