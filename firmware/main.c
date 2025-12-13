#include <regx52.h>
#include ".\ThuVien\Delay.h"
void main(){
	while(1){
	P2_0 = 1;	
	P2_1 = 0;
	P2_2 = 0;
	P2_3 = 1;
	P2_4 = 1;
	P2_5 = 1;
	P2_6 = 1;
	P2_7 = 1;
	Delay_ms(1000);
	P2 = 0xA4;
	Delay_ms(1000);
	}
}
