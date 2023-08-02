#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, i;
    int y = 1; // Initialize y to 1, assuming the number is prime.

    cout << "Give me a number: ";
    cin >> x;

    if (x <= 1) {
        cout << "Not a prime number" << endl;
        return 0;
    }

    for (i = 2; i < x; i++) {
        if (x % i == 0) {
            y = 0; // If the number is divisible by any i, set y to 0 (not prime).
            break; // Break out of the loop as we don't need to check further.
        }
        // If the number is not divisible by the current i, set y to 1 (still potentially prime).
    }

    if (y == 1) {
        cout << "Prime number" << endl;
    } else {
        cout << "Not a prime number" << endl;
    }

    return 0;
}
