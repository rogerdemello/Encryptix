#include <iostream>
using namespace std;

int main() {
    double fnum, snum, result ;
    char operation;

    cout << "Enter the first number: ";
    cin >> fnum;

    cout << "Enter the operation: ";
    cin >> operation;

    cout << "Enter the second number: ";
    cin >> snum;

    switch (operation) {
        case '+':
            result = fnum + snum;
            cout << "Result: " << fnum << " + " << snum << " = " << result << endl;
            break;
        case '-':
            result = fnum - snum;
            cout << "Result: " << fnum << " - " << snum << " = " << result << endl;
            break;
        case '*':
            result = fnum * snum;
            cout << "Result: " << fnum << " * " << snum << " = " << result << endl;
            break;
        case '/':
            if (snum != 0) {
                result = fnum / snum;
                cout << "Result: " << fnum << " / " << snum << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            break;
    }

    return 0;
}
