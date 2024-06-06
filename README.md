# Introduction

This is a Bachelor's Final Project made by Juan Llinares Mauri and supervised by Sergio Cuenca Asensi.

# Objectives

The main objective of this project is to create ML model able to predict the resilience of a given program under the effects of radiation.

This is achieved using the PARIS tool. 

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
  1. [Computation Kernel Dataset](https://github.com/HPCCS/Computation-Kernel-Dataset).
  2. [TheAlgorithms/C](https://github.com/TheAlgorithms/C).

We had to convert the code from the Computation Kernel Dataset from C++ to C.

## LLVM-Tracer

This tool can be found here: [LLVM-Tracer](https://github.com/harvard-acc/LLVM-Tracer). With it, we extracted the dynamic trace of our dataset.

We used [this](https://hub.docker.com/repository/docker/xyzsam/gem5-aladdin) docker image to install it. This solved basically all environment issues. The image is also referenced in the tool's repository.

## gem5-aladdin

This tool is required to run LLVM-Tracer. We didn't touch anything of this tool and it came with the installation of the docker image we previously mentioned.

You can find the repository of gem5-aladdin [here](https://github.com/harvard-acc/gem5-aladdin).

## PARIS

With this tool ([PARIS repository](https://github.com/HPCCS/PARIS)) we processed all the dynamic traces extracted with LLVM-Tracer and got every feature we needed in order to construct the 30 feature vector for the ML model.

## UN-FIT

We used this fault injector to run our fault injection campaign over the dataset we have. It can be found [here](https://github.com/UNPLaS/UN-FIT).
