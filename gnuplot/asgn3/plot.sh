#!/usr/bin/env bash

rm -f /tmp/{heap,insertion,quick,shell}.dat

for i in {1..100}; do
    awk -F, '{
	
        split($1, name, " ");
        split($2, elements, " ");
        split($3, moves, " ");
	split($4, compares, " ");
	file = sprintf("/tmp/%s.dat", tolower(name[1]));
	printf ("%d %d %d\n", elements[1], moves[1], compares[1]) >> file
}' <(./sorting -a -n $(( 10 * i)) -p 0)

done
gnuplot <<EOF
set terminal pdf
set key outside
set bmargin 4
set xlabel "Elements"
set size ratio 0.75

set output "moves.pdf"
set title "Moves Performed"
set ylabel "Moves"
plot "/tmp/heap.dat" using 1:2 with linespoint title "Heap", \
     "/tmp/insertion.dat" using 1:2 with linespoint title "Insertion", \
    "/tmp/quick.dat" using 1:2 with linespoint title "Quick", \
     "/tmp/shell.dat" using 1:2 with linespoint  title "Shell"

set output "compares.pdf"
set title "Compares Performed"
set ylabel "Compares"
plot "/tmp/heap.dat" using 1:3 with linespoint title "Heap", \
     "/tmp/insertion.dat" using 1:3 with linespoint linestyle 2 title "Insertion", \
    "/tmp/quick.dat" using 1:3 with linespoint title "Quick", \
     "/tmp/shell.dat" using 1:3 with linespoint title "Shell"


EOF
echo "done."

