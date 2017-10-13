all: main.o input.o initial_curves.o destroy.o
	gcc -o proj main.o input.o initial_curves.o destroy.o -g

main.o: main.c
	gcc -c -g main.c

input.o: input.c
	gcc -c -g input.c

initial_curves.o: initial_curves.c
	gcc -c -g initial_curves.c

destroy.o: destroy.c
	gcc -c -g destroy.c
