#include "lcd.h"

// 내부 변수
static int lcd_fd = -1;

// 내부 함수: 명령어 또는 데이터 전송
void lcd_send_byte(int bits, int mode) {
    int high_bits = mode | (bits & 0xF0) | LCD_BACKLIGHT;
    int low_bits = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT;

    // Enable 신호 전송
    wiringPiI2CWrite(lcd_fd, high_bits);
    wiringPiI2CWrite(lcd_fd, high_bits | LCD_ENABLE);
    usleep(500);
    wiringPiI2CWrite(lcd_fd, high_bits & ~LCD_ENABLE);
    wiringPiI2CWrite(lcd_fd, low_bits);
    wiringPiI2CWrite(lcd_fd, low_bits | LCD_ENABLE);
    usleep(500);
    wiringPiI2CWrite(lcd_fd, low_bits & ~LCD_ENABLE);
}

// LCD 초기화
void lcd_init() {
    if ((lcd_fd = wiringPiI2CSetup(LCD_I2C_ADDR)) < 0) {
        printf("LCD I2C 초기화 실패!\n");
        return;
    }

    lcd_send_byte(0x33, LCD_CMD); // 초기화 명령어
    lcd_send_byte(0x32, LCD_CMD);
    lcd_send_byte(0x06, LCD_CMD); // Cursor 이동
    lcd_send_byte(0x0C, LCD_CMD); // Display On
    lcd_send_byte(0x28, LCD_CMD); // 4비트 모드, 2줄
    lcd_send_byte(0x01, LCD_CMD); // 화면 클리어
    usleep(500);
}

// LCD 화면 지우기
void lcd_clear() {
    lcd_send_byte(0x01, LCD_CMD); // Clear display 명령어
    usleep(500);
}

// LCD 문자열 출력
void lcd_write(int line, const char *s) {
    lcd_send_byte(line, LCD_CMD); // 해당 줄로 커서 이동
    for (int i = 0; i < strlen(s); i++) {
        lcd_send_byte(s[i], LCD_CHR); // 문자 전송
    }
}
