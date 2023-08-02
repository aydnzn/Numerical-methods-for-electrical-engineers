#include <iostream>
#include <new>
using namespace std;

template <class T>
class MyVector {
public:
    int size;
    T* data;

    MyVector(); // Default constructor
    MyVector(int n); // Parameterized constructor to create a vector of size n
    MyVector(int n, T value); // Parameterized constructor to create a vector of size n with initial value

    void print(); // Print the elements of the vector

    MyVector operator+ (const MyVector& v); // Overloaded operator+ to add two vectors element-wise
    T operator* (const MyVector& v); // Overloaded operator* to perform dot product of two vectors
};

template <class T>
MyVector<T>::MyVector() {
    size = 0;
    data = nullptr;
}

template <class T>
MyVector<T>::MyVector(int n) {
    size = n;
    data = new T[size];
}

template <class T>
MyVector<T>::MyVector(int n, T value) {
    size = n;
    data = new T[size];
    for (int i = 0; i < n; i++) {
        data[i] = value;
    }
}

template <class T>
void MyVector<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T>
MyVector<T> MyVector<T>::operator+ (const MyVector& v) {
    MyVector<T> result(size);

    for (int i = 0; i < size; i++) {
        result.data[i] = this->data[i] + v.data[i];
    }

    return result;
}

template <class T>
T MyVector<T>::operator* (const MyVector& v) {
    T dotProduct = 0;

    for (int i = 0; i < size; i++) {
        dotProduct += this->data[i] * v.data[i];
    }

    return dotProduct;
}

int main() {

    int size = 3;

    MyVector<float> a(size, 1.1);
    MyVector<float> b(size, 2.2);

    a.print();
    b.print();

    MyVector<float> c;

    c = a + b;
    c.print();

    cout << a * b << endl;

    return 0;
}
