#include <REGX52.H>
#include "i2c.h"
#include "delay.h"

sbit SCL = P1^0;  // C?ng ra xung clock sang DS1307
sbit SDA = P1^1;  // C?ng nh?n data t? DS1307

void SCL_high() {
    SCL = 1;
    delay_short();
}

void SCL_low() {
    SCL = 0;
    delay_short();
}

void I2C_Start() {
    SDA = 1;
    SCL = 1;
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
        SCL_high();
        SCL_low();
    }
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
    if (ack) SDA = 0; 
    else SDA = 1;
    SCL_high();
    SCL = 0;
    SDA = 1; 
    delay_short();
    return(dat);
}
