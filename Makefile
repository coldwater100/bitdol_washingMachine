washer.exe : database.o motor.o
	gcc -o main.exe database.o motor.o main.o `mysql_config --libs`

main.o : main/main.c
	gcc -c -o main.o main/main.c

database.o : database/database.c database/database.h
	gcc -c -o database.o database/database.c `mysql_config --cflags`

motor.o : motor/motor.c motor/motor.h
	gcc -c -o motor.o motor/motor.c



clean:
	rm -f *.o main.exe
