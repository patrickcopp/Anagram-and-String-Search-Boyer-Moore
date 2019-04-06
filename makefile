all: P11 P12 P21 P22 P23

P11: P11.c
	gcc -Wall -pedantic -std=c99 P11.c -o P11

P12: P12.c
	gcc -Wall -pedantic -std=c99 P12.c -o P12

P21: P21.c
	gcc -Wall -pedantic -std=c99 P21.c -o P21

P22: P22.c
	gcc -Wall -pedantic -std=c99 P22.c -o P22

P23: P23.c
	gcc -Wall -pedantic -std=c99 P23.c -o P23
