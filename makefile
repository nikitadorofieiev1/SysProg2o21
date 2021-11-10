all: A.exe B.exe

A.o: A.c
	gcc -c A.c -o A.o

A.exe: A.o
	gcc A.o -o A.exe

B.o: B.c
	gcc -c B.c -o B.o

B.exe: B.o
	gcc B.o -o B.exe
