#include <REGX52.H>	
//		
void Delay_ms (unsigned int t) {
	unsigned int x, y;
	for (x = 0; x < t; x++){
		for (y = 0; y < 123; y++);
	}
}
//	
void main(){
	while (1){
		P0 = 0x0F;
		Delay_ms (500);
		P0 = 0xF0;
		Delay_ms (500);
		P0 = 0x55;
		Delay_ms (500);
		P0 = 0xAA;
		Delay_ms (500);
	}
}
