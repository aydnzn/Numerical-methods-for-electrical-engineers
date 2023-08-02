#include <iostream>
using namespace std;

// Class CVector representing a 2D vector
class CVector {
public:
    int x, y;
    CVector() {}
    CVector(int a, int b) : x(a), y(b) {}
    CVector operator+(const CVector&);
};

// Overloaded operator+ to add two CVector objects
CVector CVector::operator+(const CVector& param) {
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

// Class Dummy representing a dummy object
class Dummy {
public:
    static int n;
    Dummy() { n++; }

    // Function to check if 'this' object is the same as the 'param' object
    bool isitme(Dummy& param);
};

// Static member initialization
int Dummy::n = 0;

// Function to check if 'this' object is the same as the 'param' object
bool Dummy::isitme(Dummy& param) {
    return &param == this;
}

int main() {
    CVector foo(3, 1);
    CVector bar(1, 2);
    CVector result;
    result = foo + bar;
    cout << result.x << ',' << result.y << '\n';

    Dummy* a = new Dummy();
    Dummy* b = new Dummy();
    Dummy c;

    cout << a->n << " " << Dummy::n << '\n';

    delete a;
    delete b;

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {32, 32, 35, 565, 76};

    if (b->isitme(c))
        cout << "yes, 'c' is 'b'\n";
    
    return 0;
}
