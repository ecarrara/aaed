#!/bin/bash

for algo in insertion selection bubble heap merge quick cartesiantree; do
    for n in 10 100 1000 10000 100000 1000000; do
        for f in 0.0 0.3 0.5 0.7 1.0; do
            for a in t f; do
                for r in t f; do
                    if [ ! -e "./results/raw/${algo}_${n}_${f}_${a}_${r}.txt" ]; then
                        /usr/bin/time --verbose -o ./results/raw/${algo}_${n}_${f}_${a}_${r}.txt ./p1 $algo $n $f $a $r
                    fi
                done
            done
        done
    done
done
