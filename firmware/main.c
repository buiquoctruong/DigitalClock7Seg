#include <regx52.h>
unsigned char dem, tam;
unsigned char dvi, chuc; 
unsigned char tram;
void main(){
	dem = 234;
	dvi = dem%10;	
	chuc = dem%100;
	chuc = chuc/10;
	tam = chuc << 4;
	tam |= dvi;
	P2 = tam;
	tram = dem/100;
	P3 = tram;
	while(1){
	}
}
