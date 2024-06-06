#!/bin/bash

dir1="$1"
dir2="$2"

# Verificar si se proporcionan dos directorios como argumentos
if [ -z "$dir1" ] || [ -z "$dir2" ]; then
    echo "Usage: $0 <directory1> <directory2>"
    exit 1
fi

# Verificar si los directorios existen
if [ ! -d "$dir1" ] || [ ! -d "$dir2" ]; then
    echo "One or both directories do not exist."
    exit 1
fi

# Comprobar archivos en dir1 que no están en dir2
echo "Archivos en $dir1 que no están en $dir2:"
for file in "$dir1"/*; do
    filename=$(basename "$file")
    if [ ! -e "$dir2/$filename" ]; then
        echo "$filename"
    fi
done

# Comprobar archivos en dir2 que no están en dir1
echo "Archivos en $dir2 que no están en $dir1:"
for file in "$dir2"/*; do
    filename=$(basename "$file")
    if [ ! -e "$dir1/$filename" ]; then
        echo "$filename"
    fi
done
