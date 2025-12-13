#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\dichNoiTiep.h"
#include ".\ThuVien\i2c.h"
#include ".\ThuVien\RTC.h"

unsigned char maLED7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90}; 
unsigned char giay, phut, gio;

void docDS1307() {
    giay = docRTC (0x00);
    phut = docRTC (0x01);
    gio = docRTC (0x02);
}

void hienThi() {
    dichNoiTiep (maLED7[giay % 10]);
    led6 = 1; delay(2); led6 = 0;
    dichNoiTiep (maLED7[giay / 10]);
    led5 = 1; delay(2); led5 = 0;
   
    dichNoiTiep (maLED7[phut % 10]);
    led4 = 1; delay(2); led4 = 0;
    dichNoiTiep (maLED7[phut / 10]);
    led3 = 1; delay(2); led3 = 0;
 
    dichNoiTiep (maLED7[gio % 10]);
    led2 = 1; delay(2); led2 = 0;
    dichNoiTiep (maLED7[gio / 10]);
    led1 = 1; delay(2); led1 = 0;
}

void main() {
    while (1) {
        docDS1307();
        hienThi();
    }
}
