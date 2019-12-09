# ME 701 - Homework 10


## Problem 1 - 6 points

Use OpenMP to parallelize the dot-product program implemented in `dot.cc`.
Then, log onto Beocat and open an interactive session on a compute node by
using the following command:

```bash
srun --nodes=1 --ntasks-per-node=1 --cpus-per-task=16 --pty bash
```

Using `bash` scripts, `Python` scripts, or any other tool at your disposal,
perform an experiment to asses what the parallel speedup and parallel
efficiency are for the program as a function of the number of threads used.
Here, parallel speedup is `s = time(1)/time(n)` for `n` threads, while the
parallel efficiency is `eff(%) = 100*s/n`.  Include plots of both in your
final repository.
