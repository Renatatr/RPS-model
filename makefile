rps: dat
	gcc -O3 src/rps.c src/ic.c src/op.c -static -lgsl -lgslcblas -lm

dat:
	mkdir -p dat
