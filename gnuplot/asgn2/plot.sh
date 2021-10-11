#!/usr/bin/env bash

make clean && make

./mathlib-test -a| awk -F, '{
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

set output "comparison.pdf"
set title "e() vs. M_E()"
plot "/tmp/computed.dat" with linespoints title "e()", \
    "/tmp/library.dat" with linespoints title "M_E()"
EOF
echo "done."

