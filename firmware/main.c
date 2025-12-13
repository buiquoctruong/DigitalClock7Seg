#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\I2C.h"

unsigned char maLED7[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define DiaChiPCF8574 0x20

void HienThiLED7(unsigned char so) {
    I2C_Start();
    I2C_Write(DiaChiPCF8574 << 1);
    I2C_Write(maLED7[so]);
    I2C_Stop();
}

void main() {
    unsigned char so = 0;
    while (1) {
        HienThiLED7(so);
        so++;
        if (so > 9) so = 0;
        Delay_ms(500);
    }
}
