a.out: Main.o Encrypt.o Decrypt.o
	gcc Main.o Encrypt.o Decrypt.o 

Main.o: Main.c
	gcc -c Main.c
 
Encrypt.o: Encrypt.c
	gcc -c Encrypt.c

Decrypt.o: Decrypt.c
	gcc -c Decrypt.c