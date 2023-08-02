#include <iostream>
#include <string>
using namespace std;

// Function prototypes
int addition(int a, int b = 6); // We use a default value for 'b'
void printer(); // Function to print a message
int mult(int& x, int& y); // Function to multiply two numbers using references
int fact(int a); // Function to calculate the factorial of a number

int main() {
    int a = 6;
    cout << a << "! = " << fact(a);

    return 0;
}

// Function to add two numbers, 'b' has a default value of 6 if not provided
int addition(int a, int b) {
    int toplam;
    toplam = a + b;
    return toplam;
}

// Function to print a message
void printer() {
    cout << "Tryhard" << endl;
}

// Function to multiply two numbers using references
int mult(int& x, int& y) {
    x = 2 * x;
    y *= 2;
    return x * y;
}

// Function to calculate the factorial of a number recursively
int fact(int a) {
    if (a > 1) {
        return a * fact(a - 1);
    } else {
        return 1;
    }
}
