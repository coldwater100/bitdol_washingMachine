#ifndef MOTOR_H
#define MOTOR_H

#include <wiringPi.h>
#include <softPwm.h>

/**
 * 핀 번호 정의 (WiringPi 기준)
 * - ENA: PWM 핀 (GPIO 18)
 * - IN1: 방향 제어 핀 1 (GPIO 4)
 * - IN2: 방향 제어 핀 2 (GPIO 5)
 */
#define ENA 1   // PWM 핀
#define IN1 7   // 방향 제어 핀 1
#define IN2 21  // 방향 제어 핀 2

/**
 * 모터를 정방향으로 회전
 * @param speed - 모터 속도 (0~100)
 *
 * 사용법:
 * 1. WiringPi 초기화:
 *    if (wiringPiSetup() == -1) {
 *        printf("WiringPi 초기화 실패!\n");
 *        return 1;
 *    }
 * 2. 핀 모드 설정:
 *    pinMode(ENA, OUTPUT);
 *    pinMode(IN1, OUTPUT);
 *    pinMode(IN2, OUTPUT);
 * 3. PWM 초기화:
 *    if (softPwmCreate(ENA, 0, 100) != 0) {
 *        printf("PWM 초기화 실패!\n");
 *        return 1;
 *    }
 * 4. 함수 호출:
 *    motor_forward(50);  // 50% 속도로 정방향 회전
 */
void motor_forward(int speed);

/**
 * 모터를 역방향으로 회전
 * @param speed - 모터 속도 (0~100)
 *
 * 사용법:
 * 동일하게 WiringPi 초기화와 핀 설정 후, 아래처럼 호출:
 *    motor_backward(75);  // 75% 속도로 역방향 회전
 */
void motor_backward(int speed);

/**
 * 모터를 정지
 *
 * 사용법:
 * 초기화와 설정 후, 아래처럼 호출:
 *    motor_stop();  // 모터 정지
 */
void motor_stop();

#endif // MOTOR_H
