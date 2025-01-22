#include "motor.h"
#include <stdio.h>

/**
 * 모터를 정방향으로 회전
 * @param speed - 모터 속도 (0~100)
 */
void motor_forward(int speed) {
    printf("IN1 : %d, IN2 : %d, speed : %d",digitalRead(IN1),digitalRead(IN2),speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    softPwmWrite(ENA, speed);  // 속도 설정 (0~100)
}

/**
 * 모터를 역방향으로 회전
 * @param speed - 모터 속도 (0~100)
 */
void motor_backward(int speed) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    softPwmWrite(ENA, speed);  // 속도 설정 (0~100)
}

/**
 * 모터를 정지
 */
void motor_stop() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    softPwmWrite(ENA, 0);  // 속도 0
}
