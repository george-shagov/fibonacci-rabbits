#!/bin/sh

the_n=5

if [ $# -eq 1 ]; then
    the_n=$1
fi

rseqfld="./r-seq"

for n in `seq 1 $the_n`; do
    ff=`ls -r $rseqfld | head -1`;
    ./rabbit-seq $rseqfld/$ff;
done
