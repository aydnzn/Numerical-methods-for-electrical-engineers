#include <cstdlib>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>

using namespace std;

int main() {

    // Part 1: Reading and printing data from "b.txt"

    ifstream b("b.txt"); // Open file "b.txt" for reading
    string line;

    int n = 0;

    // Count the number of lines in the file
    if (b.is_open()) {
        while (!b.eof()) {
            getline(b, line);
            n = n + 1;
        }
    }

    // Set the file read position back to the beginning
    b.seekg(0, ios::beg);

    // Dynamically allocate memory to store the data in an array
    float* matrixb;
    matrixb = new float[n];

    // Read data from the file and store it in the array
    for (int i = 0; i < n; i++) {
        b >> matrixb[i];
    }

    // Print the data from the array
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << matrixb[i] << endl;
    }

    // Deallocate the memory for the array to prevent memory leaks
    delete[] matrixb;


    // Part 2: Reading and printing data from "A.txt"

    ifstream a("A.txt");

    int n2 = 0;

    // Count the number of lines in the file
    if (a.is_open()) {
        while (!a.eof()) {
            getline(a, line);
            n2 = n2 + 1;
            // n2 row number
        }
    }

    // Set the file read position back to the beginning
    a.seekg(0, ios::beg);

    stringstream is(line);
    int n4 = 0;
    int n3;
    while (is >> n3) {
        n4 = n4 + 1;
        // n4 column number
    }

    // Dynamically allocate memory for a 2D array to store the data
    float** matrixa = new float* [n2];
    for (int i = 0; i < n2; i++) {
        matrixa[i] = new float[n4];
    }

    // Read data from the file and store it in the 2D array
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n4; j++) {
            a >> matrixa[i][j];
        }
    }

    // Print the data from the 2D array
    cout << endl;
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n4; j++) {
            cout << matrixa[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate the memory for the 2D array to prevent memory leaks
    for (int i = 0; i < n2; ++i) {
        delete[] matrixa[i];
    }
    delete[] matrixa;

    return 0;
}
