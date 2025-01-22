#ifndef FLOW_SENSOR_H
#define FLOW_SENSOR_H

#include <wiringPi.h>

#ifdef __cplusplus
extern "C" {
#endif

// 유량 센서 핀 번호 (필요에 따라 수정하세요)
#define FLOW_SENSOR_PIN 2 // GPIO 핀 번호

// 유량 센서의 스케일 (L/min per Hz, 데이터시트 참고)
#define FLOW_SCALE 45.0

/**
 * @brief 유량 센서 인터럽트 핸들러
 *
 * 이 함수는 유량 센서로부터 입력 신호의 상승 에지(Rising Edge)를 감지했을 때 호출됩니다.
 * 내부적으로 마지막 에지 발생 시간과 에지 간격을 업데이트합니다.
 */
void flow_sensor_ISR();

/**
 * @brief 유량 센서 초기화 함수
 *
 * 유량 센서를 초기화하고 인터럽트를 설정합니다.
 * WiringPi 초기화와 GPIO 핀 설정을 수행합니다.
 *
 * 사용 예시:
 * @code
 * flow_sensor_init();
 * @endcode
 */
void flow_sensor_init();

/**
 * @brief 유량 계산 함수
 *
 * 유량 센서 신호의 주기를 기반으로 유량(L/min)을 계산합니다.
 * 신호가 없거나 유효하지 않으면 0.0을 반환합니다.
 *
 * @return float 계산된 유량 값 (L/min)
 *
 * 사용 예시:
 * @code
 * float flow_rate = calculate_flow_rate();
 * printf("Flow Rate: %.2f L/min\n", flow_rate);
 * @endcode
 */
float calculate_flow_rate();

#ifdef __cplusplus
}
#endif

#endif // FLOW_SENSOR_H
