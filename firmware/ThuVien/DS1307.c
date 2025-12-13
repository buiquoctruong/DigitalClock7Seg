#include <REGX52.H>
#include "RTC.h"
#include "i2c.h"
unsigned char docRTC (unsigned char add){
  unsigned char dat;
  // gui dia chi RTC
  I2C_Start();
  I2C_Write (0xd0);
  I2C_Write (add);
  // gui yeu cau doc
  I2C_Start();
  I2C_Write (0xd1);
  // doc du lieu
  dat = I2C_Read(0);
  I2C_Stop();
  // chuyen doi du lieu
  dat = (dat&0x0f) + (dat >>4)*10;
  // tra ve du li?u
  return (dat);
}
