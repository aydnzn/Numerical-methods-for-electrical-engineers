# Project 1: Gaussian Elimination with Partial Pivoting

This repository contains the work done for Project 1: Gaussian Elimination with Partial Pivoting, as a part of Numerical Methods for Electrical Engineering course.

## Project Overview

The aim of this project is to implement the Gaussian elimination algorithm with partial pivoting along with backward substitution to solve the equation `Ax = b`, where `A` is a `n x n` square matrix.

## Contents

- [source.cpp](/Project1/source.cpp): This is the primary program file written in C++.
- [readme.txt](/Project1/readme.txt): This file includes instructions for compiling and running the program.
- [A.txt](/Project1/A.txt): is a `n x n` square matrix.
- [B.txt](/Project1/B.txt): is vector `b` in `Ax = b`.
- [output.txt](/Project1/output.txt): the solution `x` in `Ax = b`.

## Compilation and Execution

- The program accepts two command-line arguments, the filenames from where the matrix `A` and the vector `b` are to be read. 
- Each line in the file represents a row of the matrix/vector.

## Additional Features

- The program can handle matrices of any size, and uses dynamically allocated memory to store them.
- If the matrix `A` is detected to be singular, the program will print an error message and terminate.
- In the case of `2x2` matrices, the program is also able to calculate the condition numbers at points `1` and `∞`, and output these numbers.

## Sample Run

This is a sample run of the program with a `2x2` matrix:

```plaintxt
A = [1.000 1.000;
1.000 1.001]
b1 = [2.000 ; 2.000]
b2 = [2.000 ; 2.001]
```
```plaintxt
Condition number at 1 = 4003.81
Condition number at infinity = 4003.81
```

Solution for Ax1 = b1
```plaintxt
x1 = [2 ; 0]
```
Solution for Ax2 = b2
```plaintxt
x2 = [1.00012 ; 0.999881]
```
The high condition number illustrates the inherent problem when dealing with small errors in the input, which can result in large errors in the output.

## How to Compile and Run

To run the program, you need to follow these steps:

1. **Install Xcode Command Line Tools**: This can be done by executing the following command in your terminal:

    ```bash
    xcode-select --install
    ```

    This command installs the necessary developer tools on MacOS. If you're using a different operating system, you need to install the appropriate C++ compiler.

2. **Compile the C++ Program**: After confirming the installation of the compiler, navigate to the directory containing `source.cpp` and compile the code by running:

    ```bash
    g++ -o source source.cpp
    ```

    This command instructs the g++ compiler to compile `source.cpp` and output (`-o`) the executable to a file named `source`.

3. **Execute the Program**: You can run the compiled program with the command:

    ```bash
    ./source A.txt B.txt
    ```

    This command starts the execution of the program `source`, taking `A.txt` and `B.txt` as input files for the matrix `A` and the vector `b`, respectively.

