source.cpp is a program computing Eigenvalues and Eigenvectors using Normalized Power Iteration together with Deflation.
The program receives 3 command line arguments. 
First one is A.txt. The second one is 0.000001. Third one is B.txt. 
A.txt should include a square matrix. First the program reads the matrix inside A.txt in a class matrix. 
Then it operates Normalized power iteration.
It finds the dominant eigenvalue and the corresponding eigenvector. 
Using this eigenvector we find a H (Householder transformation matrix).
The program operates the algoritm on page 179 of book "Scientific Computing" by Michael T. Heath.
Then it finds the second eigenvalue.
The source.cpp is fully commented. The algorithm is easy to understand.
The solutions are recorded into B.txt file.
The A.txt and B.txt files should be at the same location with source file.
By the way there should be no blank spaces between the lines.


AYDIN UZUN
2015401210
EE 242
Project 1

http://www.cplusplus.com/forum/
https://stackoverflow.com/
These two sites are essentials for me. Whenever I have a problem, I look at this two sites.


examples: 
1- 
A.txt
3.1200 2.1200 3.4100
4.1200 4.3200 7.5400
4.5400 12.2200 9.5600

B.txt
Eigenvalue#1: 18.53
0.31
0.62
1.00
Eigenvalue#2: 2.78

Solve it in Matlab.
Eigenvalues: 
18.5252
1.2565
-2.7817

Eigenvectors:
-0.2522   -0.8776   -0.1798
-0.5097    0.0003   -0.6651
-0.8225    0.4794    0.7247

Comment : 18.53 is true.The eigenvector I found is multiple of first column of eigenvectors. [-0.2522; -0.5097 ; -0.8225]
This eigencvector has size 1. But my eigenvector don't. You don't want us to make its size 1. Just like in the example you gave us.
So the eigenvector is true. Let's come to second eigenvalue. I found positive but It should be negative. The normalized power iteration
algortihm gives us the absolute value of eigenvalue. Therefore the eigenvalue I found is positive

Example 2:
A.txt
0.5499    0.3510    0.2399    0.4173
0.1450    0.5132    0.1233    0.0497
0.8530    0.4018    0.1839    0.9027
0.6221    0.0760    0.2400    0.9448

B.txt
Eigenvalue#1: 1.65
0.64
0.23
1.00
0.92
Eigenvalue#2: 0.54

Matlab eigenvalues and eigenvectors:
    0.4201    0.2258   -0.7457   -0.3176
    0.1509    0.1262    0.2592   -0.7189
    0.6575   -0.9631   -0.1456   -0.0044
    0.6069    0.0748    0.5962    0.6183


    1.6543         0         0         0
         0   -0.1389         0         0
         0         0    0.1411         0
         0         0         0    0.5353

Comment: 1.65 and 0.54 are true. My eigenvector is multiple of the first column of eigenvector matrix computed by matlab.

