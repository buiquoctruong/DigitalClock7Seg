#ifndef I2C_H
#define I2C_H
void SCL_high ();
void SCL_low ();
void I2C_Star ();
void I2C_Stop ();
bit I2C_Write (unsigned char dat);
unsigned char I2C_Read (bit ack);
#endif
