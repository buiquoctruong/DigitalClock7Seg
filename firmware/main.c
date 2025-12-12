#include <REGX52.H>
sbit LED2 = P3^7;
void main(){
	unsigned long i;
	while (1){
		LED2 = 1;
		for (i = 0; i < 22000; i++);
		LED2 = 0;
		for (i = 0; i < 22000; i++);
	}
}
