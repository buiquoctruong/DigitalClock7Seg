#include <regx52.h>
unsigned char dem, tam = 0;
unsigned char dvi, chuc = 0;
void main(){
	dem = 234;
	dvi = dem%10;
	chuc = dem%100;			chuc = chuc/10;
	tam = chuc << 4;		
	tam |= dvi;
	P2 = tam;
	while(1){
	}
}
