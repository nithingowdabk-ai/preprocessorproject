C Preprocessor Project

Project Description

This project implements a simple C preprocessor using the C programming language.

The program accepts a C source file as a command-line argument and generates a preprocessed output file with the ".i" extension.

Features

1. Comment Removal
   
   - Removes single-line comments ("//").
   - Removes multi-line comments ("/* ... */").

2. File Inclusion
   
   - Detects "#include <filename>".
   - Opens the specified header file.
   - Replaces the include statement with the contents of that file.

3. Macro Replacement
   
   - Supports object-like macros.
   - Supports function-like macros.
   - Replaces macro names with their corresponding values or expressions.

Project Files

File| Description
"main.c"| Main program and function calls
"preprocessor.h"| Header file containing function declarations
"comment_removal.c"| Removes comments from the source file
"header_includes.c"| Handles header file inclusion
"macro_replace.c"| Performs macro replacement
"Makefile"| Compiles the project
"inputfile1.c"| Input C source file
"myheader.h"| Sample user-defined header file

Compilation

Compile the project using:

make

Alternatively, compile manually:

cc main.c comment_removal.c header_includes.c macro_replace.c -o mypreprocessor

Execution

Run the executable by providing the input C filename:

./mypreprocessor inputfile.c

Output

The program generates a preprocessed file:

inputfile.i

To view the output:

cat inputfile.i

Technologies Used

- C Programming
- File Handling
- String Handling
- C Preprocessor Concepts
- Linux Terminal
- Makefile


