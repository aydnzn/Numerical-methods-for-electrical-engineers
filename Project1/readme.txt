source.cpp is a program performing Gaussian Elimination with partial pivoting.
The program receives 2 input txt.files, matrix A and vector B.
'A' should be a nxn matrix to solve the equation.
It detects the size of matrix A.
Then it merges matrix A and vector B into augmented matrix.
Then reordering, elimination and in the end backward elimination happen.
So it solves the equation Ax =B.
The source.cpp is fully commented. The algorithm is easy to understand.
The solution is recorded into output.txt file and it is printed on the command window too.
The program can detect the singularity of matrix A. 
If the A matrix is a 2x2 matrix. The program can calculate the condition numbers of matrix A at point 1 and at infinity.
It prints the condition numbers on the command window.
The A.txt and B.txt files should be at the same location with source file.
By the way there should be no blank spaces between the lines.

A = [1.000 1.000;
1.000 1.001]
b1 = [2.000 ; 2.000]
b2 = [2.000 ; 2.001]
For A,
The condition number at 1 is 4003.81.
The condition number at infinity is 4003.81.
Solution for Ax1=b1
x1 = [2 ; 0]
Solution for Ax2=b2
x2 = [1.00012 ; 0.999881]

Changes in the input data get multiplied by the condition number to produce changes in
the outputs. Thus a high condition number is bad. It shows that small errors in the input can cause large
errors in the output.

AYDIN UZUN
2015401210
EE 242
Project 1

