#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\dichNoiTiep.h"
#include ".\ThuVien\i2c.h"
#include ".\ThuVien\RTC.h"

unsigned char maLED7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
unsigned char giay, phut, gio, ngay, thang, nam;
unsigned char kt = 0;

bit cheDo0 = 1, cheDo1 = 1;
bit caiDat0 = 1, caiDat1 = 1; 
bit tang1 = 1, tang0 = 1, giam0 = 1, giam1 = 1;

void docDS1307() {
    giay = docRTC(0x00);
    phut = docRTC(0x01);
    gio = docRTC(0x02);
    ngay = docRTC(0x04);
    thang = docRTC(0x05);
    nam = docRTC(0x06);
}

void ktPhim() {
    cheDo0 = cheDo1;
    cheDo1 = cheDo;
    if ((cheDo0 == 1) && (cheDo1 == 0)) {
        kt = !kt;
    }
}

void hienThi() {
    if (kt == 0) {
        dichNoiTiep(maLED7[giay % 10]);
        led6 = 1; delay(2); led6 = 0;
        dichNoiTiep(maLED7[giay / 10]);
        led5 = 1; delay(2); led5 = 0;
        dichNoiTiep(maLED7[phut % 10]);
        led4 = 1; delay(2); led4 = 0;
        dichNoiTiep(maLED7[phut / 10]);
        led3 = 1; delay(2); led3 = 0;
        dichNoiTiep(maLED7[gio % 10]);
        led2 = 1; delay(2); led2 = 0;
        dichNoiTiep(maLED7[gio / 10]);
        led1 = 1; delay(2); led1 = 0;
    } else {
        dichNoiTiep(maLED7[ngay % 10]);
        led2 = 1; delay(2); led2 = 0;
        dichNoiTiep(maLED7[ngay / 10]);
        led1 = 1; delay(2); led1 = 0;
        dichNoiTiep(maLED7[thang % 10]);
        led4 = 1; delay(2); led4 = 0;
        dichNoiTiep(maLED7[thang / 10]);
        led3 = 1; delay(2); led3 = 0;
        dichNoiTiep(maLED7[nam % 10]);
        led6 = 1; delay(2); led6 = 0;
        dichNoiTiep(maLED7[nam / 10]);
        led5 = 1; delay(2); led5 = 0;
    }
}

void main() {
    while (1) {
        ktPhim();
        docDS1307();
        hienThi();
    }
}
