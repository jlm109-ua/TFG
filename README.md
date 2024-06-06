# Introduction

This is a Bachelor's Final Project made by Juan Llinares Mauri and supervised by Sergio Cuenca Asensi.

# Objectives

# Usage

Firstly, you will have to mount the container:
```
$ sudo sh mount_docker.sh
```

Then, install LLVM-Tracer. The guide to do so is in the LLVM-Tracer's repository (https://github.com/harvard-acc/LLVM-Tracer).

Now, basically, you have everything you need in order to make the project work. 

If you want to run your C code and extract the dynamic trace of it you will need to move or copy your code to the directory /workspace/DATASET/c/. **Caution! You will need to do all this inside the docker image, otherwise the programs won't find the correct path.** When you complete this step, you can go to the location /workspace/LLVM-Tracer/playground/ and execute the python program called _get_dynamic_traces.py_:

```
python3 get_dynamic_traces.py
```

This last command will try to extract the dynamic traces from every single code located at /workspace/DATASET/c/, so if you only want the trace of your code you can delete or move all the other files. If everything goes as planned, the dynamic trace will be located at /workspace/LLVM-Tracer/playground/output/.

# External Tools & Repositories

We used some external repositories to achieve our goals. 

## Dataset

We used the next two repositories as our dataset:
  1. https://github.com/HPCCS/Computation-Kernel-Dataset.
  2. https://github.com/TheAlgorithms/C

We had to convert the code from the Computation Kernel Dataset from C++ to C.

## LLVM-Tracer

This tool can be found here: https://github.com/harvard-acc/LLVM-Tracer. With it, we extracted the dynamic trace of our dataset.

We used a docker image to install it. This solved basically all environment issues. The image is referenced in the tool's repository.

## gem5-aladdin

This tool is required to run LLVM-Tracer. We didn't touch anything of this tool.

## PARIS
