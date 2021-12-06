#!/usr/bin/env bash

rm -f /tmp/{stats}.dat

for i in {1..100}; do
    awk -F, '{
	split($1, name, " ");
        split($2, bst_size, " ");
        split($3, bst_height, " ");
	split($4, avg_bst_size, " ");
	split($5, avg_bst_height, " ");
        split($6, avg_bst_branches, " ");
	split($7, HashTable, " ");
        split($8, BloomFilter, " ");
	file = sprintf("/tmp/%s.dat", tolower(name[1]));
	printf ("%u %u %0.6f %0.6f %0.6f %0.6f %0.6f\n",bst_size[1],bst_height[1],avg_bst_size[1],avg_bst_height[1],avg_bst_branches[1],HashTable[1],BloomFilter[1]) >> file
}' <(./banhammer -s -t $((i)) <script.txt )

done
gnuplot <<EOF
set terminal pdf
set key outside
set bmargin 4
set xlabel "HashTable"
set size ratio 0.75

set output "ABS.pdf"
set title "Average BST Size vs Height"
set ylabel "avg_bst_size"
plot "/tmp/stats.dat" using 1:3 with lines linestyle 1 title "Size", \
     "/tmp/stats.dat" using 1:4 with lines linestyle 2 title "Height", \

set output "bt.pdf"
set title "Branches Traversed"
set ylabel "Average Branches Traversed"
plot "/tmp/stats.dat" using 1:5 with lines linestyle 1 title "Branches", \


EOF
echo "done."

