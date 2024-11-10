#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

// 핀 번호 정의 (WiringPi 기준)
#define ENA 1   // PWM 핀 (GPIO 18)
#define IN1 7   // 방향 제어 핀 1 (GPIO 4)
#define IN2 21  // 방향 제어 핀 2 (GPIO 5)

// 모터 제어 함수
void motor_forward(int speed) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    softPwmWrite(ENA, speed);  // 속도 설정 (0~100)
}

void motor_backward(int speed) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    softPwmWrite(ENA, speed);  // 속도 설정 (0~100)
}

void motor_stop() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    softPwmWrite(ENA, 0);  // 속도 0
}

int main() {
    // WiringPi 초기화
    if (wiringPiSetup() == -1) {
        printf("WiringPi 초기화 실패!\n");
        return 1;
    }

    // 핀 모드 설정
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    // PWM 초기화
    if (softPwmCreate(ENA, 0, 100) != 0) {
        printf("PWM 초기화 실패!\n");
        return 1;
    }

    printf("모터 제어 시작\n");

    // 모터 정방향 50% 속도
    printf("모터 정방향 회전\n");
    motor_forward(50);
    delay(2000);  // 2초 대기

    // 모터 역방향 75% 속도
    printf("모터 역방향 회전\n");
    motor_backward(75);
    delay(2000);  // 2초 대기

    // 모터 정지
    printf("모터 정지\n");
    motor_stop();
    delay(2000);  // 2초 대기

    printf("모터 제어 종료\n");
    return 0;
}
