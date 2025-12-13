#include <regx52.h>
#include ".\ThuVien\Delay.h"
#include ".\ThuVien\port.h"
#include ".\ThuVien\dichNoiTiep.h"
#include ".\ThuVien\i2c.h"
#include ".\ThuVien\RTC.h"

unsigned char maLED7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
unsigned char giay, phut, gio, ngay, thang, nam;
unsigned char kt = 0, a = 0;

bit cheDo0 = 1, cheDo1 = 1;
bit caiDat0 = 1, caiDat1 = 1; 
bit tang1 = 1, tang0 = 1, giam0 = 1, giam1 = 1;

void ghiDS1307() {
    ghiRTC(0x00, giay);
    ghiRTC(0x01, phut);
    ghiRTC(0x02, gio);
    ghiRTC(0x04, ngay);
    ghiRTC(0x05, thang);
    ghiRTC(0x06, nam);
}

void docDS1307() {
    if (kt == 0) {
        if (a == 1) {
            ghiDS1307();
            a = 0;
        }
        giay = docRTC(0x00);
        phut = docRTC(0x01);
        gio = docRTC(0x02);
        ngay = docRTC(0x04);
        thang = docRTC(0x05);
        nam = docRTC(0x06);
    }
}

void ktPhim() {
    cheDo0 = cheDo1; cheDo1 = cheDo;
    if ((cheDo0 == 1) && (cheDo1 == 0)) {
        if (kt == 0) kt = 4;
        else if (kt == 4) kt = 0;
        else kt = 0;
    }
    caiDat0 = caiDat1; caiDat1 = caiDat;
    if ((caiDat0 == 1) && (caiDat1 == 0)) {
        kt++;
        if (kt == 3) kt = 1;
        else if (kt == 8) kt = 5;
    }

    switch (kt) {
        case 1: {
            tang0 = tang1; tang1 = tang; a = 1;
            if ((tang0 == 1) && (tang1 == 0)) {
                gio++;
                if (gio > 23) gio = 0;
            }
            giam0 = giam1; giam1 = giam;
            if ((giam0 == 1) && (giam1 == 0)) {
                gio--;
                if (gio == 255) gio = 23;
            }
            break;
        }
        case 2: {
            tang0 = tang1; tang1 = tang; a = 1;
            if ((tang0 == 1) && (tang1 == 0)) {
                phut++;
                if (phut > 59) phut = 0;
            }
            giam0 = giam1; giam1 = giam;
            if ((giam0 == 1) && (giam1 == 0)) {
                phut--;
                if (phut == 255) phut = 59;
            }
            break;
        }
        case 5: {
            tang0 = tang1; tang1 = tang; a = 1;
            if ((tang0 == 1) && (tang1 == 0)) {
                ngay++;
                if (ngay > 31) ngay = 1;
            }
            giam0 = giam1; giam1 = giam;
            if ((giam0 == 1) && (giam1 == 0)) {
                ngay--;
                if (ngay == 0) ngay = 31;
            }
            break;
        }
        case 6: {
            tang0 = tang1; tang1 = tang; a = 1;
            if ((tang0 == 1) && (tang1 == 0)) {
                thang++;
                if (thang > 12) thang = 1;
            }
            giam0 = giam1; giam1 = giam;
            if ((giam0 == 1) && (giam1 == 0)) {
                thang--;
                if (thang == 0) thang = 12;
            }
            break;
        }
        case 7: {
            tang0 = tang1; tang1 = tang; a = 1;
            if ((tang0 == 1) && (tang1 == 0)) {
                nam++;
                if (nam > 99) nam = 0;
            }
            giam0 = giam1; giam1 = giam;
            if ((giam0 == 1) && (giam1 == 0)) {
                nam--;
                if (nam == 255) nam = 99;
            }
            break;
        }
    }
}

void hienThi() {
    if (kt == 0) {
        dichNoiTiep(maLED7[giay % 10]); led6 = 1; delay(2); led6 = 0;
        dichNoiTiep(maLED7[giay / 10]); led5 = 1; delay(2); led5 = 0;
    }
    if ((kt == 0) || (kt == 1)) {
        dichNoiTiep(maLED7[gio % 10]); led2 = 1; delay(2); led2 = 0;
        dichNoiTiep(maLED7[gio / 10]); led1 = 1; delay(2); led1 = 0;
    }
    if ((kt == 0) || (kt == 2)) {
        dichNoiTiep(maLED7[phut % 10]); led4 = 1; delay(2); led4 = 0;
        dichNoiTiep(maLED7[phut / 10]); led3 = 1; delay(2); led3 = 0;
    }
    if ((kt == 4) || (kt == 5)) {
        dichNoiTiep(maLED7[ngay % 10]); led2 = 1; delay(2); led2 = 0;
        dichNoiTiep(maLED7[ngay / 10]); led1 = 1; delay(2); led1 = 0;
    }
    if ((kt == 4) || (kt == 6)) {
        dichNoiTiep(maLED7[thang % 10]); led4 = 1; delay(2); led4 = 0;
        dichNoiTiep(maLED7[thang / 10]); led3 = 1; delay(2); led3 = 0;
    }
    if ((kt == 4) || (kt == 7)) {
        dichNoiTiep(maLED7[nam % 10]); led6 = 1; delay(2); led6 = 0;
        dichNoiTiep(maLED7[nam / 10]); led5 = 1; delay(2); led5 = 0;
    }
}

void main() {
    while (1) {
        ktPhim();
        docDS1307();
        hienThi();
    }
}
