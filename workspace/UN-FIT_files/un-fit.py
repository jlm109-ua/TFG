import os

INJECTIONS_PER_KERNEL = 50

# Comprobamos si es un kernel.
def is_kernel(file):
    blackList = ["input_files", "output_files", "LICENSE", "README.md", ".vscode"]
    if not file.is_dir():
        return False
    if file.name in blackList:
        return False
    return True

# Realizamos la campaña de fallos para cada kernel
def inject():

    DATASET_C = "/home/juan/Documents/TFG/workspace/DATASET/c"
    count = 0

    with os.scandir(DATASET_C) as dir:
        for file in dir:
            if is_kernel(file):
                command = "clear"
                os.system(command)
                count += 1

                print("%i - Injecting faults in %s" % (count, file.name))
                
                print("Copying %s.c to the root directory..." % file.name)
                command = "cp %s/%s/%s.c ." % (DATASET_C, file.name, file.name)
                os.system(command)

                print("Creating Makefile...")
                command = "sed \'s/KERNEL/%s/g\' Mtemplate > Makefile" % file.name
                os.system(command)

                print("Compiling kernel...")
                command = "make"
                os.system(command)

                print("Instrumenting kernel...")
                command = "sudo bash pc_trace_v2.sh %s.elf 0 vexpress-a15 100M 0x8000003c" % file.name
                os.system(command)

                print("Injecting faults...")
                command = "sudo bash UNFIT-arm-qemu.sh %s.elf vexpress-a15 100M %i 0 0 1 6" % (file.name, INJECTIONS_PER_KERNEL)
                os.system(command)

                print("Reading results...")
                UNFIT_KERNEL = "/home/juan/Documents/TFG/workspace/UN-FIT/kernel"
                RESULTS = UNFIT_KERNEL + "/results"
                f_output = open(UNFIT_KERNEL + "/Result.txt")
                lines = f_output.readlines()
                for line in lines:
                    if line.startswith("Tot"):
                        line_replace = line.replace("|", "")
                        line_replace = line.replace("\t\t", "\t")
                        values = line_replace.split("\t")
                        unACE = values[1]
                        sdc = values[2]
                        hang = values[3]
                        total = INJECTIONS_PER_KERNEL * 16
                        unACE = float(unACE) / total
                        sdc = float(sdc) / total
                        hang = float(hang) / total

                        print("Saving results in %s/%s.txt" % (UNFIT_KERNEL + RESULTS, file.name))
                        f_result = open(UNFIT_KERNEL + RESULTS + "/%s.txt" % file.name, "w")
                        f_result.write("%f\t%f\t%f" % (unACE, sdc, hang))
                        f_result.close()

                print("Cleaning directory...")
                command = "sudo rm -f *.c *.elf *.o *_dis.s *.txt *.out"
                os.system(command)
                
                f_output.close()


if __name__ == "__main__":
    inject()
