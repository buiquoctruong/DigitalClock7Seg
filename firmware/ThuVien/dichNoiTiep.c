#include <REGX52.H>
#include "..\ThuVien\port.h"


void dichNoiTiep (unsigned char duLieu){
	unsigned char i;	
	for (i=0; i<8; i++){
		DS = duLieu&(0x80>>i) ? 1 : 0; 
		SHCP = 0; SHCP = 1;
	}
	STCP = 0; STCP = 1;
}
