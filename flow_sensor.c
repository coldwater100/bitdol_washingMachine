#include "flow_sensor.h"
#include <stdio.h>

volatile unsigned long last_time = 0;      // 마지막 에지 발생 시간
volatile unsigned long pulse_interval = 0; // 에지 간격 (마이크로초)

// 인터럽트 핸들러
void flow_sensor_ISR() {
    unsigned long current_time = micros();
    pulse_interval = current_time - last_time;
    last_time = current_time;
}

// 유량 센서 초기화
void flow_sensor_init() {
    if (wiringPiSetup() == -1) {
        printf("WiringPi 초기화 실패!\n");
        return;
    }
    pinMode(FLOW_SENSOR_PIN, INPUT);
    if (wiringPiISR(FLOW_SENSOR_PIN, INT_EDGE_RISING, &flow_sensor_ISR) < 0) {
        printf("유량 센서 인터럽트 설정 실패!\n");
    }
}

// 유량 계산 함수
float calculate_flow_rate() {
    if (pulse_interval == 0) {
        return 0.0; // 유효하지 않은 신호
    }
    float frequency = 1000000.0 / pulse_interval;
    return frequency / FLOW_SCALE;
}

