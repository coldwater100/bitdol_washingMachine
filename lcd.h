#ifndef LCD_H
#define LCD_H

#include <wiringPiI2C.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * @file lcd.h
 * @brief I2C LCD 제어 모듈 헤더 파일
 *
 * 이 모듈은 I2C를 통해 라즈베리파이에서 LCD를 제어할 수 있는 기능을 제공합니다.
 * 16x2 또는 20x4 I2C LCD 패널에서 동작합니다.
 *
 * 사용법:
 * 1. LCD 초기화:
 *    - lcd_init();
 *    - LCD를 초기화하고 기본 설정을 완료합니다.
 *
 * 2. LCD 화면에 문자열 출력:
 *    - lcd_write(LCD_LINE1, "Hello World!");
 *    - 첫 번째 줄에 "Hello World!"를 출력합니다.
 *    - lcd_write(LCD_LINE2, "Raspberry Pi");
 *    - 두 번째 줄에 "Raspberry Pi"를 출력합니다.
 *
 * 3. LCD 화면 지우기:
 *    - lcd_clear();
 *    - LCD 화면을 초기화하고 커서를 첫 번째 줄로 이동합니다.
 *
 * @note I2C 주소와 LCD 크기는 LCD 데이터 시트를 확인 후 적절히 설정하십시오.
 */

// LCD I2C 주소 (보통 0x27이나 0x3F)
#define LCD_I2C_ADDR 0x27

// LCD 명령어
#define LCD_CMD 0
#define LCD_CHR 1
#define LCD_LINE1 0x80 // 첫 번째 줄
#define LCD_LINE2 0xC0 // 두 번째 줄
#define LCD_BACKLIGHT 0x08 // 백라이트 ON
#define LCD_ENABLE 0x04 // Enable bit

/**
 * @brief LCD 초기화 함수
 *
 * LCD를 초기화하고 기본 설정을 완료합니다.
 * 초기화 시 백라이트가 켜지며, 화면이 지워집니다.
 *
 * 사용 예시:
 * @code
 * lcd_init();
 * @endcode
 */
void lcd_init(void);

/**
 * @brief LCD 화면 지우기
 *
 * LCD 화면을 지우고 커서를 첫 번째 줄로 이동합니다.
 *
 * 사용 예시:
 * @code
 * lcd_clear();
 * @endcode
 */
void lcd_clear(void);

/**
 * @brief LCD에 문자열 출력
 *
 * LCD의 특정 줄에 문자열을 출력합니다.
 * 출력할 문자열이 LCD 크기를 초과하면 자동으로 잘립니다.
 *
 * @param line LCD 줄 (LCD_LINE1 또는 LCD_LINE2)
 * @param s 출력할 문자열
 *
 * 사용 예시:
 * @code
 * lcd_write(LCD_LINE1, "Hello, World!");
 * lcd_write(LCD_LINE2, "Raspberry Pi");
 * @endcode
 */
void lcd_write(int line, const char *s);

#endif // LCD_H
