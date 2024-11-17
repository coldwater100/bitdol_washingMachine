#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#define BLUETOOTH_DEVICE "/dev/serial0" // 블루투스 장치 파일 경로
#define BAUD_RATE 9600                 // UART 통신 속도

void bluetooth_init(void);            // 블루투스 초기화
void bluetooth_send(const char *msg); // 메시지 전송
void bluetooth_receive(char *buffer, int length); // 메시지 수신

#endif // BLUETOOTH_H
