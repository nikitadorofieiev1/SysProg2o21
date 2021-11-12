RPS.exe: lab2.o
	gcc lab2.o -o RPS.exe
	
lab2.o: lab2.c
	gcc -c lab2.c -o lab2.o
