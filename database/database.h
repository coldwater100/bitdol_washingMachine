#ifndef DATABASE_H
#define DATABASE_H

#include <mysql.h>

/**
 * 데이터베이스 연결 함수
 * @return MYSQL* - 데이터베이스 연결 객체
 *
 * 사용 예시:
 * MYSQL *conn = connect_to_database();
 */
MYSQL* connect_to_database();

/**
 * 데이터 삽입 함수
 * @param conn - MYSQL* 객체 (데이터베이스 연결 객체)
 * @param name - 삽입할 데이터의 이름
 * @param usage - 삽입할 데이터의 세제 사용량
 *
 * 사용 예시:
 * insert_data(conn, "test_name", "15");
 */
void insert_data(MYSQL *conn, const char *name, const char *usage);

/**
 * 데이터 조회 함수
 * @param conn - MYSQL* 객체 (데이터베이스 연결 객체)
 * @param row_count - 결과의 행(row) 개수 (출력 파라미터)
 * @param col_count - 결과의 열(column) 개수 (출력 파라미터)
 * @return char*** - 동적으로 할당된 2차원 배열 (data[row][col] 형태)
 *
 * 사용 예시:
 * int rows, cols;
 * char ***data = fetch_data(conn, &rows, &cols);
 * for (int i = 0; i < rows; i++) {
 *     for (int j = 0; j < cols; j++) {
 *         printf("%s ", data[i][j] ? data[i][j] : "NULL");
 *     }
 *     printf("\n");
 * }
 */
char*** fetch_data(MYSQL *conn, int *row_count, int *col_count);

/**
 * 동적 메모리 해제 함수
 * @param data - char*** 형태의 동적으로 할당된 데이터 배열
 * @param row_count - 해제할 행(row)의 개수
 * @param col_count - 해제할 열(column)의 개수
 *
 * 사용 예시:
 * free_data(data, rows, cols);
 */
void free_data(char ***data, int row_count, int col_count);

#endif // DATABASE_H
