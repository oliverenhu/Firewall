#!/usr/bin/env bash

make clean && make

./mathlib-test -m|awk -F, '{
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

set output "Madhava.pdf"
set title "pi_madhava() vs. M_PI()"
plot "/tmp/computed.dat" with linespoints title "pi_madhava()", \
    "/tmp/library.dat" with linespoints title "M_PI()"
EOF
echo "done."

