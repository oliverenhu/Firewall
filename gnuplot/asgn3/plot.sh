#!/usr/bin/env bash

make clean && make

./sorting -a|awk -F, '{
	split($1,computed, " ");
	split(computed[1], x, " ")
    	split($2, library, " ");
    	print x[2], computed[3] > "/tmp/computed.dat"
    	print x[2], library[3] > "/tmp/library.dat"
}'

echo -n "Plotting... "
gnuplot <<EOF
set terminal pdf
set key outside
set zeroaxis

set output "Sorting.pdf"
set title "Elements vs. Moves"
plot "/tmp/computed.dat" with lines linestyle 1 title "Elements", \
    "/tmp/library.dat" with linespoints title "Moves"
EOF
echo "done."

