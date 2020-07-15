#!/usr/bin/env python
"""Muito chato fazer as tabelas LaTeX na mão.

Percorre os arquivos no diretório com os outputs do comando perf
e extraí o tempo de execução para montar uma tabela LaTeX.
"""

import sys
from glob import glob
from collections import defaultdict


tmpl = r"""\begin{{tabular}}{{lccclll}}
                        & \multicolumn{{6}}{{c}}{{\textbf{{Quantidade de Elementos}}}}                                                                                           \\
    \textbf{{Algoritmo}} & \textbf{{10}}      & \textbf{{100}}     & \textbf{{1.000}}    & \textbf{{10.000}}   & \textbf{{100.000}}   & \textbf{{1.000.000}}  \\ \hline
    InsertionSort      & {insertion[10]}      & {insertion[100]}   & {insertion[1000]}   & {insertion[10000]}  & {insertion[100000]}  & {insertion[1000000]}  \\
    SelectionSort      & {selection[10]}      & {selection[100]}   & {selection[1000]}   & {selection[10000]}  & {selection[100000]}  & {selection[1000000]}  \\
    BubbleSort         & {bubble[10]}         & {bubble[100]}      & {bubble[1000]}      & {bubble[10000]}     & {bubble[100000]}     & {bubble[1000000]}     \\
    HeapSort           & {heap[10]}           & {heap[100]}        & {heap[1000]}        & {heap[10000]}       & {heap[100000]}       & {heap[1000000]}       \\
    MergeSort          & {merge[10]}          & {merge[100]}       & {merge[1000]}       & {merge[10000]}      & {merge[100000]}      & {merge[1000000]}      \\
    QuickSort          & {quick[10]}          & {quick[100]}       & {quick[1000]}       & {quick[10000]}      & {quick[100000]}      & {quick[1000000]}      \\
    CartesianTreeSort  & {cartesiantree[10]}      & {cartesiantree[100]}   & {cartesiantree[1000]}   & {cartesiantree[10000]}  & {cartesiantree[100000]}  & {cartesiantree[1000000]}  \\ \hline
\end{{tabular}}"""

result = defaultdict(lambda: {})

for filepath in glob(f"./results/perf/*_*_{sys.argv[1]}.txt"):
    contents = [l for l in open(filepath, "r").readlines()]
    cmd = contents[3].split("'")[1].split()
    testset = cmd[2].rsplit("/", 1)[-1]
    size = int(testset.split("_")[0])

    algo = cmd[1]  # .capitalize() + "Sort"
    time, unit = contents[5].strip().split()[0:2]

    if unit != "msec":
        raise RuntimeError("ops!")

    time = float(time.replace(",", "")) / 1000  # convert to seconds

    result[algo][size] = "{:0.05f}s".format(time)

print(tmpl.format(**result))
