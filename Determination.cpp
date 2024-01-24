#include <iostream>
#include <cmath>

using namespace std;
// code that find the determinants of roots by using the discriminant 
string determine_roots(int a, int b, int c) {
    // Check if it's a quadratic equation
    if (a == 0) {
        return "Not a quadratic equation";
    }

    // Calculate the discriminant
    int discriminant = b*b - 4*a*c;

    // Determine the nature of the roots
    if (discriminant > 0) {
        return "Real roots";
    } else if (discriminant == 0) {
        return "Equal roots";
    } else {
        return "Imaginary roots";
    }
}

int main() {
    // Get user input for coefficients
    int a, b, c;
    cout << "Enter the value of a (positive integer): ";
    cin >> a;
    cout << "Enter the value of b (positive integer): ";
    cin >> b;
    cout << "Enter the value of c (positive integer): ";
    cin >> c;

    // Check if values are in the specified interval [0, 100]
    if (0 <= a && a <= 100 && 0 <= b && b <= 100 && 0 <= c && c <= 100) {
        // Call the function and print the result
        string result = determine_roots(a, b, c);
        cout << result << endl;
    } else {
        cout << "Values should be in the interval [0, 100]" << endl;
    }

    return 0;
}
