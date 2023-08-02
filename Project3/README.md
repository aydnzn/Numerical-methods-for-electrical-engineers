# Project 3: Secant and Bisection Methods in Numerical Methods

This repository contains the source code (`source.cpp`) and README (`readme.txt`) for Project 3, focused on implementing the secant and bisection methods to solve 𝑓(𝑥) = 0 for any given polynomial.

## Project Objectives

1. Develop a C++ program that accepts command-line inputs of the coefficients of a polynomial function, initial guesses, and a tolerance value.
2. The program should return the calculated roots of the given polynomial and the number of iterations required for each implemented method.
3. Implement both the secant and bisection methods separately.
4. Develop a hybrid method combining both the secant and bisection methods. Start with the bisection method for the first two iterations, then proceed with the secant method for the rest of the iterations. 

## Project Details

- Input: You will have `n+1` command-line arguments for the coefficients of the polynomial 𝑓(𝑥) = 𝑎𝑛𝑥^n + 𝑎𝑛-1𝑥^n-1 + ⋯+ 𝑎1𝑥 + 𝑎0, in the order from 𝑎𝑛 to 𝑎0. These coefficients should be dynamically stored.
- Additional arguments include two initial guesses (`x1` and `x2`, where `x2` > `x1`), and a tolerance value `tol`.

## Running the Program

To compile and run the program, refer to the instructions in the included [readme](/Project2/README.md) file. 

## Example

Command-line arguments: `2 2 -7 1 -7 1.5 1.8 0.001`

This will solve the equation `2𝑥^4 + 2𝑥^3 − 7𝑥^2 + 𝑥 − 7 = 0` and find a root close to 1.67.

Output is:

```
number of iterations for the bisection method: 9
result from the bisection method: 1.66934
number of iterations for the secant method: 4
result from the secant method: 1.66941
number of iterations for the hybrid method: 5
result from the hybrid method: 1.66941
```

## Repository Contents

- [ProjectDescription.pdf](/Project3/ProjectDescription.pdf): Detailed project description.
- [source.cpp](/Project3/source.cpp): Main program file written in C++.
- [readme.txt](/Project3/readme.txt): Compilation and execution instructions.

