#include <REGX52.H>
#include "..\ThuVien\port.h"


void dichDuLieuHienThi (unsigned char Data){
	unsigned char i;	
	for (i=0; i<8; i++){
		DS = Data&(0x80>>i) ? 1 : 0; 
		SHCP = 0; SHCP = 1;
	}
	STCP = 0; STCP = 1;
}
