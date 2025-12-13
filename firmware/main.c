#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\I2C.h"

unsigned char maLED7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

#define DiaChiPCF8574_1 0x20
#define DiaChiPCF8574_2 0x21

void HienThiLED7 (unsigned char so) {
    I2C_Start();
    I2C_Write(DiaChiPCF8574_1 << 1);
    I2C_Write(maLED7[so]);
    I2C_Stop();
}

unsigned char DocNutNhan() {
    unsigned char trangThaiNut;
    I2C_Start();
    I2C_Write (DiaChiPCF8574_2 << 1 | 1);
    trangThaiNut = I2C_Read(1);
    I2C_Stop();
    return trangThaiNut;
}

void main() {
    unsigned char trangThaiNut;
    unsigned char so = 0;
    bit daNhan = 0;
    I2C_Start();
    I2C_Write (DiaChiPCF8574_1 << 1);
    I2C_Write(0xFF);
    I2C_Stop();
    HienThiLED7(so);
    while (1) {
        trangThaiNut = DocNutNhan();
        if ((trangThaiNut & 0x01) == 0 && daNhan == 0) {
            so++;
            if (so > 9) so = 0;
            HienThiLED7(so);
            daNhan = 1;
        }
        if ((trangThaiNut & 0x01) == 1) {
            daNhan = 0;
        }
        Delay_ms(100);
    }
}
