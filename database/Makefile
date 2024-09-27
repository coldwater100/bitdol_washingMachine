main.exe : test.o
	gcc -o washer.exe test.o `mysql_config --cflags --libs`

test.o : test.c
	gcc -c -o test.o test.c `mysql_config --cflags --libs`