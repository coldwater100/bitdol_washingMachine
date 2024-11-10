#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 데이터베이스 연결 함수
MYSQL* connect_to_database() {
    MYSQL *conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (!mysql_real_connect(conn, "localhost", "washer", "0000", NULL, 3306, NULL, 0)) {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    printf("Connected to MySQL server: %s\n", mysql_get_server_info(conn));
    return conn;
}

// 데이터 삽입 함수
void insert_data(MYSQL *conn, const char *name, const char *usage) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO `detergent`.`table` (`name`, `detergent usage`) VALUES ('%s', '%s');", name, usage);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "INSERT query failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }
    printf("Data inserted: name='%s', detergent usage='%s'\n", name, usage);
}

// 데이터 조회 및 반환 함수
char*** fetch_data(MYSQL *conn, int *row_count, int *col_count) {
    if (mysql_query(conn, "SELECT * FROM detergent.table;")) {
        fprintf(stderr, "SELECT query failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "No result: %s\n", mysql_error(conn));
        exit(1);
    }

    *row_count = mysql_num_rows(result);
    *col_count = mysql_num_fields(result);

    // 이중 포인터 배열 할당 (rows)
    char ***data = (char***)malloc((*row_count) * sizeof(char**));
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        mysql_free_result(result);
        exit(1);
    }

    int row_index = 0;
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        // 각 row에 대해 columns 할당
        data[row_index] = (char**)malloc((*col_count) * sizeof(char*));
        if (!data[row_index]) {
            fprintf(stderr, "Memory allocation failed\n");
            mysql_free_result(result);
            exit(1);
        }

        for (int col_index = 0; col_index < *col_count; col_index++) {
            data[row_index][col_index] = row[col_index] ? strdup(row[col_index]) : NULL;
        }
        row_index++;
    }

    mysql_free_result(result);
    return data;
}

// 동적 메모리 해제 함수
void free_data(char ***data, int row_count, int col_count) {
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
}
