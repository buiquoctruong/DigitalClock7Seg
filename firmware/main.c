#include <REGX52.H>
void main(){
	unsigned long i;
	P0 = 0x00;
	while (1){
		P0 = 0x0F;
		for (i = 0; i < 22000; i++);
		P0 = 0xF0;
		for (i = 0; i < 22000; i++);
		P0 = 0x55;
		for (i = 0; i < 22000; i++);
		P0 = 0xAA;
		for (i = 0; i < 22000; i++);
	}
}
