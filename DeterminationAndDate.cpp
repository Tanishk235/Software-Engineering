#include <iostream>
#include <cmath>

using namespace std;

string determine_roots(int a, int b, int c) {
    // Check if it's a quadratic equation
    if (a == 0) {
        return "Not a quadratic equation";
    }

    // Calculate the discriminant
    int discriminant = b * b - 4 * a * c;

    // Determine the nature of the roots
    if (discriminant > 0) {
        return "Real roots";
    } else if (discriminant == 0) {
        return "Equal roots";
    } else {
        return "Imaginary roots";
    }
}

bool isValidDate(int day, int month, int year) {
    // Check if the date is within the specified ranges
    return (1 <= month && month <= 12) && (1 <= day && day <= 31) && (1900 <= year && year <= 2025);
}

bool isLeapYear(int year) {
    // Check if the year is a leap year
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void determinePreviousDate(int& day, int& month, int& year) {
    // Check if the date is valid
    if (!isValidDate(day, month, year)) {
        cout << "Invalid input date" << endl;
        return;
    }

    // Handle boundary cases for months, days, and years
    if (day == 1) {
        if (month == 1) {
            // If it's January 1st, go to December 31st of the previous year
            day = 31;
            month = 12;
            year--;
        } else {
            // If it's the first day of any other month, go to the last day of the previous month
            month--;
            day = (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : (month == 2) ? (isLeapYear(year) ? 29 : 28) : 31;
        }
    } else {
        // If it's not the first day of the month, simply go to the previous day
        day--;
    }

    cout << "Previous date: " << day << "/" << month << "/" << year << endl;
}

int main() {
    // Menu for the user to choose functionality
    cout << "Choose functionality:\n";
    cout << "1. Determine nature of roots for a quadratic equation\n";
    cout << "2. Determine previous date\n";

    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Get user input for quadratic equation coefficients
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
    } else if (choice == 2) {
        // Get user input for date
        int day, month, year;
        cout << "Enter the day (1-31): ";
        cin >> day;
        cout << "Enter the month (1-12): ";
        cin >> month;
        cout << "Enter the year (1900-2025): ";
        cin >> year;

        // Call the function to determine the previous date and print the result
        determinePreviousDate(day, month, year);
    } else {
        cout << "Invalid choice. Exiting program.\n";
    }

    return 0;
}
