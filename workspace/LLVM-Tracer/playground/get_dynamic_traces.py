import os

# Directorio de los benchmarks
def control_arguments():
    global BENCHMARK_HOME

    if not 'BENCHMARK_HOME' in os.environ:
        raise Exception('Set BENCHMARK_HOME directory as an environment variable')
    else:
        BENCHMARK_HOME = os.environ['BENCHMARK_HOME']

# Comprobamos si es un kernel.
def is_kernel(file):
    blackList = ["input_files", "output_files", "LICENSE", "README.md", ".vscode"]
    if not file.is_dir():
        return False
    if file.name in blackList:
        return False
    return True

# Comprobamos si ya se ha sacado la traza dinámica para ese kernel.
def alreadyProcessed(file, path):
    name = file.name + "_dynamic_trace"
    
    problematic_files = []
    
    if file.name in problematic_files:
        return True
    
    return os.path.exists(os.path.join(path, name))


def getDynamicTrace():
    global BENCHMARK_HOME
    count = 0
    errors = []

    # Creamos las variables de entorno para el prorgama.
    C_HOME = BENCHMARK_HOME + "/c"
    PLAYGROUND_HOME = "/workspace/LLVM-Tracer/playground"
    OUTPUT = PLAYGROUND_HOME + "/output"

    # Si el directorio de salida no existe, lo creamos.
    if not os.path.exists(OUTPUT):
        os.makedirs(OUTPUT)

    with os.scandir(C_HOME) as it:
        for file in it:
            if is_kernel(file) and not alreadyProcessed(file,OUTPUT):
                count = count + 1
                print("--------------------------------")
                print("%i. Processing kernel %s..." % (count, file.name))
                # Copiamos el kernel al playground.
                command = "cp " + C_HOME + "/" + file.name + "/" + file.name + ".c " + PLAYGROUND_HOME
                os.system(command)
                # Comprobamos que no haya habido errores al copiar el kernel.
                if not os.path.exists(PLAYGROUND_HOME + "/" + file.name + ".c"):
                    print("\tError copying kernel %s" % file.name)
                    errors.append(file.name)
                    continue
                print("\tKernel copied!")
                # Compilamos el kernel mediante Makefile.tracer
                command = "make trace-binary EXEC=" + file.name + " TOP_LEVEL=runMain SUFFIX=c > /dev/null"
                os.system(command)
                # Comprobamos que no haya habido errores al compilar el kernel.
                if not os.path.exists(PLAYGROUND_HOME + "/" + file.name + "-instrumented"):
                    print("\tError compiling kernel %s" % file.name)
                    errors.append(file.name)
                    continue
                print("\tKernel compiled!")
                # Ejecutamos el kernel.
                command = "./" + file.name + "-instrumented"
                os.system(command)
                # Comprobamos que no haya habido errores al ejecutar el kernel.
                if not os.path.exists(PLAYGROUND_HOME + "/dynamic_trace.gz"):
                    print("\tError executing kernel %s" % file.name)
                    errors.append(file.name)
                    continue
                print("\tKernel executed!")
                # Movemos el archivo de traza dinámica.
                command = "mv dynamic_trace.gz output/" + file.name + "_dynamic_trace.gz"
                os.system(command)
                # Comprobamos que no haya habido errores al mover el archivo de traza dinámica.
                if not os.path.exists(OUTPUT + "/" + file.name + "_dynamic_trace.gz"):
                    print("\tError moving dynamic trace %s" % file.name)
                    errors.append(file.name)
                    continue
                os.chdir(OUTPUT)
                print("\tDynamic trace moved!")
                # Descomprimimos el archivo de traza dinámica.
                command = "gunzip " + file.name + "_dynamic_trace.gz"
                os.system(command)
                # Comprobamos que no haya habido errores al descomprimir el archivo de traza dinámica.
                if not os.path.exists(OUTPUT + "/" + file.name + "_dynamic_trace"):
                    print("\tError decompressing dynamic trace %s" % file.name)
                    errors.append(file.name)
                    continue
                print("\tDynamic trace decompressed!")
                os.chdir("..")
                # Limpiamos el directorio.
                command = "make clean > /dev/null"
                os.system(command)
                print("\tDirectory cleaned!")
                command = "rm *.c"
                os.system(command)
                print("\tKernel succesfully processed!")

    print("--------------------------------\n")
    print("Total kernels processed: %i" % count)
    print("Total errors: %i" % len(errors))
    for error in errors:
        print("\t - %s" % error)

if __name__ == "__main__":
    control_arguments()
    getDynamicTrace()
    print("FINISHED!")
