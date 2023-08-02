#include <iostream>
#include <string>
#include <new>
using namespace std;

// Define a struct to store information about people and the number of fruits they have
struct insan_meyve {
    string isim;
    int elma, armut, portakal;
};

// Function to print the information about a person and the number of fruits they have
void yazdirma(insan_meyve asd) {
    cout << asd.isim << "\n" << asd.elma << "\n" << asd.armut << "\n" << asd.portakal;
}

int main() {
    int i, n;
    
    // Declare variables to hold information about a single person and an array of people
    insan_meyve ainsan;
    insan_meyve *pinsan;

    pinsan = &ainsan;

    // Ask the user for the number of people
    cout << "Kac kisi olacak? ";
    cin >> n;
    
    // Dynamically allocate memory to hold the array of people
    pinsan = new (nothrow) insan_meyve[n];
    if (pinsan == nullptr) {
        cout << "Error: memory could not be allocated";
    } else {
        // Ask the user for information about each person and the number of fruits they have
        for (i = 0; i < n; i++) {
            cout << "Isim: ";
            cin >> pinsan[i].isim;
            cout << "Elma: ";
            cin >> pinsan[i].elma;
            cout << "Armut: ";
            cin >> pinsan[i].armut;
            cout << "Portakal: ";
            cin >> pinsan[i].portakal;
        }
    }

    // Print the information about each person and the number of fruits they have
    for (i = 0; i < n; i++) {
        yazdirma(pinsan[i]);
    }

    // Deallocate the dynamically allocated memory to prevent memory leaks
    delete[] pinsan;
}
