#include <REGX52.H>
sbit LED = P3^0;
sbit NutNhanB1 = P1^0;
void main() {
	P0 = P3 = 0;
	LED = 0; 	
	while (1){
		if ( NutNhanB1 == 0) {	
			LED = 1; 	
		}
		else {		
		 	LED = 0;
		}
	}
}
