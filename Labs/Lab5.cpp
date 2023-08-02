#include <iostream>
using namespace std;

class point {
    int x_coordinate;
    int y_coordinate;

public:
    point();
    point(int, int);
    void setx(int x) { x_coordinate = x; }
    void sety(int y) { y_coordinate = y; }
    int getx() { return x_coordinate; }
    int gety() { return y_coordinate; }
    void printcoordinates();
};

class rectangle {
    point bottomleft;
    point bottomright;
    point topleft;
    point topright;

public:
    rectangle();
    rectangle(point, point);
    void printrect();
};

// Default constructor for the class 'rectangle'
rectangle::rectangle() : bottomright(0, 1), topleft(1, 0), topright(1, 1) {}

// Parameterized constructor for the class 'rectangle'
rectangle::rectangle(point A, point B) : bottomleft(A.getx(), A.gety()), bottomright(B.getx(), A.gety()), topleft(A.getx(), B.gety()), topright(B.getx(), B.gety()) {}

// Print the coordinates of the point
void point::printcoordinates() {
    cout << x_coordinate << "," << y_coordinate << endl;
}

// Default constructor for the class 'point'
point::point() {
    x_coordinate = 0;
    y_coordinate = 0;
}

// Parameterized constructor for the class 'point'
point::point(int a, int b) {
    x_coordinate = a;
    y_coordinate = b;
}

// Print the coordinates of the rectangle
void rectangle::printrect() {
    bottomleft.printcoordinates();
    bottomright.printcoordinates();
    topleft.printcoordinates();
    topright.printcoordinates();
}

int main() {
    point A; // Create a point object with default constructor
    point B(2, 4); // Create a point object with parameterized constructor

    A.printcoordinates(); // Print coordinates of point A
    B.printcoordinates(); // Print coordinates of point B

    B.sety(5); // Set the y-coordinate of point B to 5
    B.printcoordinates(); // Print updated coordinates of point B

    rectangle kare; // Create a rectangle object with default constructor
    kare.printrect(); // Print coordinates of the rectangle kare

    rectangle dikdortgen(A, B); // Create a rectangle object with parameterized constructor
    dikdortgen.printrect(); // Print coordinates of the rectangle dikdortgen

    return 0;
}
