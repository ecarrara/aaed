#!/usr/bin/env python
import sys
from glob import glob
from collections import defaultdict
import pandas as pd


result = []

for filepath in glob(f"./results/perf/*.txt"):
    contents = [l for l in open(filepath, "r").readlines()]

    cmd = contents[3].split("'")[1].split()
    algo = cmd[1]  # .capitalize() + "Sort"

    testset = cmd[2].rsplit("/", 1)[-1].split("_")
    size = int(testset[0])
    random = float(testset[1])
    order = testset[2]
    rng = testset[3][0]

    time, unit = contents[5].strip().split()[0:2]

    if unit != "msec":
        raise RuntimeError("ops!")

    time = float(time.replace(",", "")) / 1000  # convert to seconds

    result.append(
        {
            "algo": algo,
            "size": size,
            "random": random,
            "order": order,
            "rng": rng,
            "time": time,
        }
    )

pd.DataFrame(result).to_csv(sys.stdout, index=False, sep=";")
