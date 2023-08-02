#include <iostream>
using namespace std;

// Base class 'insan' representing a person
class insan {
protected:
    float mass, height;
    float index;

public:
    // Function to set values for mass, height, and index
    void set_values(float a, float b, float c) {
        height = a;
        mass = b;
        index = c;
    }

    // Friend function to calculate the maximum weight based on the index
    friend double max_weight(insan);
};

// Derived class 'erkek' representing a male person
class erkek : public insan {
public:
    // Function to calculate the BMI (Body Mass Index) for a male person
    float bmi() {
        return mass / (height * height);
    }
};

// Derived class 'kadin' representing a female person
class kadin : public insan {
public:
    // Function to calculate the BMI (Body Mass Index) for a female person
    float bmi() {
        return mass / (height * height);
    }
};

// Function to calculate the maximum weight based on the index
double max_weight(insan x) {
    double res;
    res = x.index * x.height * x.height;
    return res;
};

int main() {
    // Create instances for male and female persons
    erkek Aydin;
    kadin Fatma;

    // Set values for Aydin and Fatma
    Aydin.set_values(1.80, 91, 25);
    Fatma.set_values(1.70, 55, 25);

    // Calculate and print the maximum weight for Aydin and Fatma
    cout << "Maximum weight for Aydin: " << max_weight(Aydin) << endl;
    cout << "Maximum weight for Fatma: " << max_weight(Fatma) << endl;

    // Calculate and print the BMI for Aydin and Fatma
    cout << "BMI for Aydin: " << Aydin.bmi() << endl;
    cout << "BMI for Fatma: " << Fatma.bmi() << endl;

    return 0;
}
