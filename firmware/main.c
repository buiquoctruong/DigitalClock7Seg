#include <regx52.h>
unsigned char maLED7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

#define DiaChiPCF8574 0x20
sbit SCL = P1^0;
sbit SDA = P1^1;

void delay_short() {
	unsigned char i;
	for (i = 0; i < 4; i++) {}
}

void delay(unsigned int time) {
    TMOD = 0x01;        
    while (time--) {
        TH0 = -1000 / 256;
        TL0 = -1000 % 256;
        TR0 = 1;
        while (!TF0);
        TR0 = 0;
        TF0 = 0;
    }
}

void SCL_high() {
	SCL = 1;
	delay_short();
}
void SCL_low() {
	SCL = 0; 
	delay_short();
}
void I2C_Start() {
	SDA = 1; SCL = 1;
	SDA = 0;
	delay_short();
	SCL = 0; 
	SDA = 1;
}
void I2C_Stop() {
	SDA = 0; 
	SCL_high();
	SDA = 1;
}

bit I2C_Write(unsigned char dat) {
	unsigned char i;
	bit outbit;
	for (i = 1; i <= 8; i++) {
		outbit = dat & 0x80;
		SDA = outbit;
		dat = dat << 1;
		SCL_high(); SCL_low();
	}
   // kiem tra ACK 
	SDA = 1; 
	SCL_high();
	outbit = SDA; 
	SCL_low();
	return(outbit); 
}

unsigned char I2C_Read(bit ack) {
    unsigned char i, dat;
    bit inbit;
    dat = 0;
    for(i = 1; i <= 8; i++) {
        SCL_high();
        inbit = SDA;
        dat = dat << 1;
        dat = dat | inbit;
        SCL_low();
    }
	// gui ACK/NACK
    if (ack) 
		SDA = 0; 
    else 
		SDA = 1;
    SCL_high();
    SCL = 0;
    SDA = 1; 
    delay_short();
    return(dat);
}

void main() {
	I2C_Start();
	I2C_Write(DiaChiPCF8574 << 1);
	I2C_Write(0xFF);
	I2C_Stop();
	while (1) {
		I2C_Start();
		I2C_Write(DiaChiPCF8574 << 1);
		I2C_Write(maLED7[1]);
		delay(1000);
		I2C_Write(maLED7[2]);
		delay(1000);
		I2C_Stop();
	}
}
