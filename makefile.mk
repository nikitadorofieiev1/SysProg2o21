game: RSP.exe

RSP.o: RSP.c
	gcc -c RSP.c -o RSP.o

RSP.exe: RSP.o
	gcc RSP.o -o RSP.exe
