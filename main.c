#include <stdio.h>
#include "motor.h"
#include "database.h"


int main(){
    if (wiringPiSetup() == -1) {
         printf("WiringPi 초기화 실패!\n");
         return 1;
    }
    printf("hi\n");
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    if (softPwmCreate(ENA, 0, 100) != 0) {
        printf("PWM 초기화 실패!\n");
        return 1;
    }
    motor_forward(50);  // 50% 속도로 정방향 회전
}