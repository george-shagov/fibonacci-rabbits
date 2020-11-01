#!/bin/sh

for f in `ls ./r-seq/r-seq.*                        \
        | grep -v 001`; do wc -c $f; done           \
        | awk '{print $1}'                          \
        | awk '{if (prev) {print $1 "/" prev} } {prev=$0}'

