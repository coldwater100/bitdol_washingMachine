main.exe : database.o
	gcc -o washer.exe database.o `mysql_config --cflags --libs`

database.o : database/database.c
	gcc -c -o database.o database/database.c `mysql_config --cflags --libs`