#ifndef _RTC_H_
#define _RTC_H_

/**********Doc du lieu thoi gian trong IC DS1307*******************/
unsigned char docRTC(unsigned char diaChi);
void ghiRTC(unsigned char diaChi, unsigned char duLieu);
void Out_1Hz();
#endif
