#!/bin/bash


for n in 10 100 1000 10000 100000 1000000; do
    for f in 0.0 0.8 0.95 1.0; do
        for a in t; do
            for r in f; do
                if [ ! -e "./results/testset/${n}_${f}_${a}_${r}.bin" ]; then
                    echo "Criando arquivo ./results/testset/${n}_${f}_${a}_${r}.bin"
                    ./generate_set ./results/testset/${n}_${f}_${a}_${r}.bin $n $f $a $r > /dev/null
                fi

                for algo in merge quick cartesiantree insertion selection bubble heap; do
                    if [ ! -e "./results/perf/${algo}_${n}_${f}_${a}_${r}.txt" ]; then
                        # dá uma mãozinha para o Kernel do Linuz colocar o arquivo em cachê na memória.
                        # cat ./results/testset/${n}_${f}_${a}_${r}.bin > /dev/null
                        echo "perf stat -o ./results/perf/${algo}_${n}_${f}_${a}_${r}.txt ./p1 $algo ./results/testset/${n}_${f}_${a}_${r}.bin"
                    fi
                done
            done
        done
    done
done
