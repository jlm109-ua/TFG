# execute_kernels.py

This little program checks the outputs of each kernel in C and compares it to the output of the C++ version. However, this doesn't work anymore because the C kernels have been edited to avoid (1) printing anything and (2) reading the input data from an external source.

To execute this program we used:

```
$ python3 execute_kernels.py
```

# DATASET

This directory contains all the kernels we used in both of their versions c and c++ (if the c++ version exists).

All the programs you can find here are from the [Computation Kernel Dataset](https://github.com/HPCCS/Computation-Kernel-Dataset) and [TheAlgorithms/C](https://github.com/TheAlgorithms/C) repositories.

# LLVM-Tracer

We did **not** make this tool. The directory of it is a submodule that redirects you to its actual repository.

The files we developed or updated are located in the [playground/](workspace/LLVM-Tracer/playground) directory:
- get_dynamic_traces.py
- Makefile
- Makefile.tracer

# gem5-aladdin

We did **not** make this tool. The directory of it contains a reference to the actual repository. We couldn't make a submodule of this one like we made with the LLVM-Tracer tool.

# PARIS

We did **not** make this tool. However, we used all the features this tool gave us.

You can find the files we created using this tool in the [PARIS_files/](workspace/PARIS_files) directory.

# PARIS_files

This is a directory that contains all the processed data from PARIS. Here you will find:
- deadloc results.
- repeatadd results.
- 4instype results.
- Scripts to make this tool work for all the kernels automatically.
- deadloc ratio results.
- combined features results.

# UN-FIT

We did **not** make this tool. We used it to do the fault injection campaign on all of our kernels.

# UN-FIT_files

In this directory you will find the results of the campaign, the Makefile template we used to compile all the kernels and the Python script we made to process every kernel automatically.
