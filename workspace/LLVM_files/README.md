# get_dynamic_traces.py

This little Python program processes each kernel and extracts its dynamic trace using the Makefile.tracer.

# Makefiles

There are two makefiles to compile LLVM-Tracer's code and execute it.

## Makefile

We did **not** develop this makefile but we had to change the value of the variable _WORKLOAD_ to _runMain_.

## Makefile.tracer

We did **not** develop this makefile but we had to change some things for the project. We added the parameter "-trace-all-callees" to the command that extracts the dynamic trace and added a new clean mode:

```
clean2:
	rm -f *.llvm
	rm -f *.o
	rm -f dynamic_trace*.gz
	rm -f *-instrumented
	rm -f full.s
	rm -f labelmap
	rm -f *.c
	rm -f output/*.gz
```

# output/

This directory contains all the dynamic traces we could extract from the kernels. 
