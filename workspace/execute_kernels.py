import os

# Comprobamos que el directorio BENCHMARK_HOME esté definido.
def control_arguments():
    global BENCHMARK_HOME

    if not 'BENCHMARK_HOME' in os.environ:
        raise Exception('Set BENCHMARK_HOME directory as an environment variable')
    else:
        BENCHMARK_HOME = os.environ['BENCHMARK_HOME'] # Directorio de los benchmarks

# Comprobamos si el directorio es un kernel.
def is_kernel(file):
    blackList = ["input_files", "output_files", "LICENSE", "README.md", ".vscode"]
    if not file.is_dir(): # Si no es un directorio, no es un kernel.
        return False
    if file.name in blackList: # Comprobamos que los nombres de la lista negra no sean escogidos.
        return False
    return True

def checkConversion():
    global BENCHMARK_HOME   # Directorio de los benchmarks
    count = 0               # Contador de kernels
    output_errors = 0       # Contador de errores en la salida
    compilation_errors = 0  # Contador de errores en la compilación

    with os.scandir(BENCHMARK_HOME + "/c") as it: # Escaneamos el directorio de kernels en C.
        for file in it: # Iteramos sobre los archivos.
            if is_kernel(file): # Comprobamos si es un kernel.
                # Comprobamos los kernels uno a uno, tanto para su versión C como C++.
                print("Checking kernel " + file.name + "...")
                cpp_dir = BENCHMARK_HOME + "/c++/" + file.name
                count = count + 1
                c_dir = BENCHMARK_HOME + "/c/" + file.name

                # Para la versión C++...
                os.chdir(cpp_dir) # Cambiamos al directorio del kernel.
                command = "make clean > /dev/null 2>&1" # Limpiamos el directorio. Los errores se redirigen a /dev/null. 2>&1 redirige los errores a la salida estándar.
                os.system(command) # Ejecutamos el comando anterior.
                command = "make > /dev/null" # Compilamos el kernel. Los errores se redirigen a /dev/null.
                os.system(command) # Ejecutamos el comando anterior.
                if not os.path.exists('test'): # Comprobamos si el kernel se ha compilado correctamente.
                    compilation_errors = compilation_errors+1 # Si no se ha compilado correctamente, incrementamos el contador de errores de compilación.
                    continue # Pasamos al siguiente kernel. (No se ejecuta el resto del bucle.)
                command = "./test > output_cc.txt" # Ejecutamos el kernel y redirigimos la salida a un archivo llamado output_cc.txt.
                os.system(command) # Ejecutamos el comando anterior.

                # C
                os.chdir(c_dir) # Cambiamos al directorio del kernel.
                command = "make clean > /dev/null 2>&1" # Limpiamos el directorio. Los errores se redirigen a /dev/null. 2>&1 redirige los errores a la salida estándar.
                os.system(command) # Ejecutamos el comando anterior.
                command = "make > /dev/null" # Compilamos el kernel. Los errores se redirigen a /dev/null.
                os.system(command) # Ejecutamos el comando anterior.
                if not os.path.exists('test'): # Comprobamos si el kernel se ha compilado correctamente.
                    compilation_errors = compilation_errors + 1 # Si no se ha compilado correctamente, incrementamos el contador de errores de compilación.
                    continue # Pasamos al siguiente kernel. (No se ejecuta el resto del bucle.)
                command = "./test > output_c.txt" # Ejecutamos el kernel y redirigimos la salida a un archivo llamado output_c.txt.
                os.system(command) # Ejecutamos el comando anterior.

                os.chdir("..") # Volvemos al directorio de los kernels.

                cpp_file = open(cpp_dir + "/output_cc.txt", encoding="utf-8") # Abrimos el archivo de salida del kernel C++.
                c_file = open(c_dir + "/output_c.txt", encoding="utf-8") # Abrimos el archivo de salida del kernel C.
                cpp_content = cpp_file.read() # Leemos el contenido del archivo de salida del kernel C++.
                c_content = c_file.read() # Leemos el contenido del archivo de salida del kernel C.

                if not cpp_content == c_content: # Comprobamos si las salidas de los kernels son iguales.
                    output_errors = output_errors + 1 # Si no son iguales, incrementamos el contador de errores de salida.
                    print("The output of the benchmarks are different.")
                    print("Output C++: ") 
                    print(cpp_content)
                    print("Output C: ")
                    print(c_content)
                    print("Checking kernel " + file.name + "...ERROR\n")
                else: # Si son iguales...
                    print("Checking kernel " + file.name + "...OK\n") # ...imprimimos que el kernel ha sido comprobado correctamente.

                # Cerramos los archivos.
                cpp_file.close() 
                c_file.close()

    # Imprimimos los resultados.
    print("Total Kernels: " + str(count))
    print("Total Compilation Errors: " + str(compilation_errors))
    print("Total Output Errors: " + str(output_errors))

if __name__ == '__main__':
    control_arguments()
    checkConversion()