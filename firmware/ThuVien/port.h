#ifndef _PORT_H_
#define _PORT_H_
// VDK ket noi voi 74HC595
sbit DS = P3^0;
sbit SHCP = P3^3;
sbit STCP = P3^2;
// VDK ket noi voi Bat/Tat LED 7 doan
sbit led1	= P1^2; // hang chuc cua Gio/Ngay
sbit led2	= P1^3; // hang don vi cua Gio/Ngay
sbit led3 = P1^4; // hang chuc cua Phut/Thang
sbit led4	= P1^5; // hang don vi cua Phut/Thang
sbit led5 = P1^6; // hang chuc cua Giay/Nam
sbit led6	= P1^7; // hang don vi cua Giay/Nam
// VDK ket noi voi DS1307 - PHDTH14
sbit SCL = P1^0;
sbit SDA = P1^1;

#endif	
