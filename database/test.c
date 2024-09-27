#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <mysql.h>

#define HOST "localhost"
#define USER "washer"
#define PASSWORD "0000"
#define DB "detergent"

int main(int argc, char* argv[]) {
    MYSQL *conn = mysql_init(NULL);
    if(!conn){
        fprintf(stderr,"%s\n",mysql_error(conn));
        exit(1);
    }

    if(!mysql_real_connect(conn,HOST,USER,PASSWORD,NULL,3306,NULL,0)){
        fprintf(stderr,"%s\n",mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    printf("%s\n",mysql_get_server_info(conn));

    if(mysql_query(conn,"INSERT INTO `detergent`.`table` (`name`, `detergent usage`) VALUES ('test', '10');")){
        fprintf(stderr,"%s\n",mysql_error(conn));
        printf("%s",mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    if(mysql_query(conn,"SELECT * FROM detergent.table;")){
        fprintf(stderr,"%s\n",mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    MYSQL_RES* result=mysql_store_result(conn);
    if(result==NULL){
        fprintf(stderr,"no result\n");
        exit(1);
    }
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while(row=mysql_fetch_row(result)){
        for(int i=0; i<num_fields; i++){
            printf("%s    ",row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(conn); 
    exit(0);
}
