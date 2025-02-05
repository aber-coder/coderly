#!/usr/bin/env bash

if [ -z "$1" ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

filename="$1"
extension="${filename##*.}"

case "$extension" in
    c)
        gcc "$filename" -o "${filename%.c}"
        ;;
    cpp)
        g++ "$filename" -o "${filename%.cpp}"
        ;;
    l)
        output_file="lex.yy.c"  
        exec_file="${filename%.l}"

        lex "$filename" && \
        gcc "$output_file" -o "$exec_file" -lfl && \
        ./"$exec_file"
        ;;
    *)
        echo "$filename is not a C, C++, or Lex source file."
        ;;
esac
