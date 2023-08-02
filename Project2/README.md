# Project 2: Computing Eigenvalues and Eigenvectors using Normalized Power Iteration together with Deflation

### Introduction

This project involves the implementation of the normalized power iteration algorithm in combination with deflation to find two eigenvalues and the corresponding eigenvector for the dominant eigenvalue of a square matrix, `A`. 

The program is implemented in C/C++, emphasizing on good programming style and the use of Object Oriented Programming concepts.

### How to Compile and Run

1. **Compile the C++ Program**: Navigate to the directory containing `source.cpp` and compile the code by running:
    ```
    g++ -o source source.cpp
    ```
2. **Execute the Program**: Run the compiled program with the command:
    ```
    ./source A.txt 1e-6 output.txt
    ```
    where, 
    - `A.txt` is the input file containing the square matrix `A`,
    - `1e-6` is the tolerance for the power iteration algorithm,
    - `output.txt` is the output file where the eigenvalues and corresponding eigenvectors are written.

### Programming Details

The program:
- Accepts three command-line arguments representing the input file, tolerance, and output file.
- Uses dynamically allocated memory to store the matrix.
- Prints an error message and exits upon detecting any problems.
- Calculates the eigenvalues and corresponding eigenvectors and writes them to a text file.

### About the OOP Approach

In this project, matrix operations are performed using a `Matrix` class, with operations such as multiplication, addition, and transposition implemented as methods of this class. This approach eliminates the need for complex loops in the program.

## Contents

- [ProjectDescription](/Project2/ProjectDescription.pdf): Project Description for details.
- [source.cpp](/Project2/source.cpp): This is the primary program file written in C++.
- [readme.txt](/Project2/readme.txt): This file includes instructions for compiling and running the program.
- [A.txt](/Project2/A.txt): is a `n x n` square matrix.
- [output.txt](/Project2/output.txt): [A](A.txt)'s dominant eigenvalue, its corresponding eigenvector and the next eigenvalue.