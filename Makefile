all:
	gcc -o closest_pair closest_pair.c kernel.c -lm -O2
