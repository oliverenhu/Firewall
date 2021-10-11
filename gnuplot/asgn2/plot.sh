#!/usr/bin/env bash

make clean && make

./mathlib-test -n|awk -F, '{
	split($1,computed, " ");
	split(computed[1], x, "[()]")
    	split($2, library, " ");
    	print x[2], computed[3] > "/tmp/computed.dat"
    	print x[2], library[3] > "/tmp/library.dat"
}'

echo -n "Plotting... "
gnuplot <<EOF
set terminal pdf
set key outside
set zeroaxis

set output "newton.pdf"
set title "pi_newton() vs. M_PI()"
plot "/tmp/computed.dat" with linespoints title "pi_newton()", \
    "/tmp/library.dat" with linespoints title "M_PI()"
EOF
echo "done."

