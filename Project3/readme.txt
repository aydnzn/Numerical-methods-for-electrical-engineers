source.cpp is a program performing Secant and Bisection Methods.
Object oriented Programming is used.
There are two constructors. One is default constructor and the other one is non-default constructor.
Copy constructor, destructor and assignment operator are already defined.
The program receives The program uses n+1 command line inputs for getting the coefficiens of the function,
the initial guesses, 
and the tolerance value.
It detects the size of command line arguments.
Then it loads defined coefficient and guess arrays.
With these two arrays and tolerance value it performs bisection method, secant method and hybrid method.
The program prints out the solution for each method, and the number of iterations required for each method on the screen. 
The program deletes the dynamically allocated arrays.


One example for command line arguments : 2 2 -7 1 -7 1.5 1.8 0.001
output is :

number of iteration of bisection method : 9
the result from bisection method : 1.66934
number of iteration of secant method : 4
the result from secant method : 1.66941
number of iteration of hybrid method : 5
the result from hybrid method : 1.66941


AYDIN UZUN
2015401210
EE 242
Project 3
aydnzn@gmail.com

