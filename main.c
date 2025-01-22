#include <stdio.h>
#include "motor.h"
#include <unistd.h>
#include "database.h"
#include "lcd.h"

int main(){


    if (wiringPiSetup() == -1) {
         printf("WiringPi 초기화 실패!\n");
         return 1;
    }
    // printf("hi\n");
    // pinMode(ENA, OUTPUT);
    // pinMode(IN1, OUTPUT);
    // pinMode(IN2, OUTPUT);
    // if (softPwmCreate(ENA, 0, 100) != 0) {
    //     printf("PWM 초기화 실패!\n");
    //     return 1;
    // }
    lcd_init();

    printf("tt");
    fflush(stdout);


    
    // motor_forward(50);  // 50% 속도로 정방향 회전
    sleep(1);
    // lcd_clear();
    sleep(1);
    while (1)
    {   
        lcd_write(1,"hii");
        printf("t");
        fflush(stdout);

        sleep(2);
        lcd_clear();
        sleep(2);

    }
    
}
