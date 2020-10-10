#!/bin/sh

the_app="./build/apps/rabbit-seq"

if [ ! -f $the_app ]; then
    echo "Application: $the_app is not found, please build the application first, see README.md for details"
    exit 1
fi

the_n=5

if [ $# -eq 1 ]; then
    the_n=$1
fi

rseqfld="./r-seq"

for n in `seq 1 $the_n`; do
    ff=`ls -r $rseqfld | head -1`;
    $the_app $rseqfld/$ff;
done
