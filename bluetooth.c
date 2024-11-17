#include "bluetooth.h"

static int bluetooth_fd = -1; // 블루투스 파일 디스크립터

// 블루투스 초기화
void bluetooth_init() {
    if (wiringPiSetup() == -1) {
        printf("WiringPi 초기화 실패!\n");
        return;
    }

    bluetooth_fd = serialOpen(BLUETOOTH_DEVICE, BAUD_RATE);
    if (bluetooth_fd == -1) {
        printf("블루투스 포트 열기 실패!\n");
        return;
    }
    printf("블루투스 초기화 완료.\n");
}

// 메시지 전송
void bluetooth_send(const char *msg) {
    if (bluetooth_fd != -1) {
        serialPuts(bluetooth_fd, msg); // 메시지 전송
        serialFlush(bluetooth_fd);    // 전송 버퍼 비우기
    }
}

// 메시지 수신
void bluetooth_receive(char *buffer, int length) {
    if (bluetooth_fd != -1 && serialDataAvail(bluetooth_fd)) {
        int index = 0;
        while (serialDataAvail(bluetooth_fd) && index < length - 1) {
            buffer[index++] = serialGetchar(bluetooth_fd); // 한 문자 읽기
        }
        buffer[index] = '\0'; // 문자열 종료
    }
}
