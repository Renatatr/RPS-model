#!/bin/bash
rm -rf dat
make
./a.out 1
cd plt
rm *.png
gnuplot phi.plt
cd .. 
