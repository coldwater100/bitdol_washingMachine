# 컴파일러와 옵션
CC = gcc
CFLAGS = -Wall `mysql_config --cflags`
LDFLAGS = `mysql_config --libs` -lwiringPi  # MySQL 라이브러리와 WiringPi 라이브러리 추가

# 최종 실행 파일 이름
TARGET = wsRasp.exe

# 오브젝트 파일 목록
OBJS = main.o motor.o database.o

# 최종 실행 파일 생성
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

# main.o 파일 생성
main.o: main.c motor.h database.h
	$(CC) -c main.c -o main.o $(CFLAGS)

# motor.o 파일 생성
motor.o: motor.c motor.h
	$(CC) -c motor.c -o motor.o $(CFLAGS)

# database.o 파일 생성
database.o: database.c database.h
	$(CC) -c database.c -o database.o $(CFLAGS)

# clean 규칙
clean:
	rm -f $(OBJS) $(TARGET)
