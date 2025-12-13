#include <REGX52.H>
#include <.\ThuVien\Delay.h>
#define LED_PORT0 P0
#define LED_PORT3 P3
sbit NutNhanB1 = P1^0;
bit PressedFlag = 0;  
unsigned char 
//	
Delay500mSvaQuetPhim() {
	unsigned char i;
	for (i=0; i<50; i++) {
		Delay_ms(10);
		if (NutNhanB1 == 0) {
			if (PressedFlag == 0) {
				PressedFlag = 1;
				return 1; 						}
		} 
		else {
			PressedFlag = 0;
		}
	}
	return 0; 	
}
//	
void main() {
	unsigned char i;
	while(1){
		LED_PORT3 = 0x00;
		LED_PORT0 = 0x00;
		for (i=0; i<20; i++) {
			if (Delay500mSvaQuetPhim()) 
				break; 		
			LED_PORT0 = ~LED_PORT0; 
		}
		LED_PORT0 = 0x55;
		for(i=0;i<20;i++) {
			if (Delay500mSvaQuetPhim()) 
				break;
			LED_PORT0 = ~LED_PORT0; 	
		}
		LED_PORT0 = 0x0F;
		for (i=0; i<20; i++) {
			if (Delay500mSvaQuetPhim()) 
				break;
			LED_PORT0 = ~LED_PORT0;
		}
	}
}
