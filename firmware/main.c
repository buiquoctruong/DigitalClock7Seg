#include <regx52.h>
#include ".\ThuVien\Delay.h"
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void main(){
	while(1){
		P2 = Code7Seg[3];
		Delay_ms(1000);
		P2 = Code7Seg[4];
		Delay_ms(1000);
	}
}
