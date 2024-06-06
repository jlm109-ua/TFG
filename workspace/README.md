# execute_kernels.py

This little program checks the outputs of each kernel in C and compares it to the output of the C++ version. However, this doesn't work anymore because the C kernels have been edited to avoid (1) printing anything and (2) reading the input data from an external source.

To execute this program we used:

```
$ python3 execute_kernels.py
```

# DATASET

This directory contains all the kernels in both of their versions: c and c++.

# LLVM-Tracer

We did **not** make this tool. The directory of it is a submodule that redirects you to its actual repository.

## LLVM_files

This directory contains the files we made in order to get the dynamic traces of each kernel.

# gem5-aladdin

We did **not** make this tool. The directory of it contains a reference to the actual repository. We couldn't make a submodule of this one like we made with the LLVM-Tracer tool.
