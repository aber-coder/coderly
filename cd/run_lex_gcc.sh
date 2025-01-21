#!/usr/bin/env bash

# Check if a file was provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 <lex_file>"
    exit 1
fi

lex_file="$1"
output_file="lex.yy.c"   # Lex generates a file named lex.yy.c by default
exec_file="${lex_file%.l}"

# Run lex to generate C source code from lex file
lex "$lex_file" && \
# Compile the C file using gcc
gcc "$output_file" -o "$exec_file" -lfl && \
# Run the compiled executable
./"$exec_file"
