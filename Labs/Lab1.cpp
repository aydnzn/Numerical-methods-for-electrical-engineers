#include <iostream>
#include <string>
using namespace std;

// Function to determine if the student is eligible for the final exam
// If the sum of MT1 and MT2 is less than 40, returns 0 (not eligible),
// otherwise returns 1 (eligible)
int eligtofinal(int m1, int m2) {
    if (m1 + m2 < 40) {
        return 0;
    } else {
        return 1;
    }
}

// Function to take input for MT1, MT2, and final exam score (if eligible),
// and then calculate and display the overall grade (Pass/Fail).
void pass() {
    int mt1, mt2, final;
    
    cout << "MT1 = ?" << endl;
    cin >> mt1;
    
    cout << "MT2 = ?" << endl;
    cin >> mt2;
    
    if (eligtofinal(mt1, mt2)) {
        cout << "Eligible for the final exam" << endl;
        
        cout << "Final = ?" << endl;
        cin >> final;
        
        if (mt1 + mt2 + final < 120) {
            cout << "F" << endl;
        } else {
            cout << "P";
        }
    } else {
        cout << "F" << endl;
    }
}

int main() {
    pass();
    return 0;
}
