#include <regx52.h>
#include ".\ThuVien\Delay.h"
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define LED7Chuc P2
#define LED7Dvi P3
void main(){
	signed char i;
	i = 12;			LED7Chuc = Code7Seg[i/10]; 
	LED7Dvi = Code7Seg[i%10];
	while(1){
	}
}
