#include <regx52.h>
#include ".\ThuVien\Delay.h"
void main(){
	unsigned char dem = 0;
	unsigned char chuc, tram, dvi, tam;
	while(1){
		dvi = dem%10;
		chuc = (dem%100)/10;
		tram = dem/100;
		tam = chuc << 4;
		tam |= dvi;
		P2 = tam;
		P3 = tram;
		Delay_ms(100);
		dem++;
		dem%=1000;
	}
}
