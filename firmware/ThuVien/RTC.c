#include <REGX52.H>
#include "RTC.h"
#include "i2c.h"

unsigned char docRTC(unsigned char diaChi) {
	unsigned char duLieu;
	I2C_Start();
	I2C_Write(0xd0);
    I2C_Write(diaChi);
    I2C_Start(); 
    I2C_Write(0xd1); 
    duLieu = I2C_Read(0);
    I2C_Stop();
    duLieu = (duLieu & 0x0f) + (duLieu >> 4) * 10;
    return (duLieu);
}

void ghiRTC(unsigned char diaChi, unsigned char duLieu) {
    I2C_Start();
    I2C_Write(0xd0);
    I2C_Write(diaChi);
    I2C_Write(((duLieu / 10) << 4) | (duLieu % 10));
    I2C_Stop();
}

void Out_1Hz() {
    I2C_Start();
    I2C_Write(0xd0);
    I2C_Write(0x07);
    I2C_Write(0x10);
    I2C_Stop();
}

