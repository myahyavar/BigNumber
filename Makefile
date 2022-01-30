all:BigNumber run

BigNumber:	main.o	islemler.o
	gcc	main.o	islemler.o	-o BigNumber

main.o:main.c
	gcc -c	main.c
islemler.o:	islemler.c	islemler.h
	gcc	-c	islemler.c
clean:
	del	*.o BigNumber.exe
run:
	BigNumber.exe