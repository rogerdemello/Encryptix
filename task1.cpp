#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main() {
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomNumber = rand() % 100 + 1;
    int guess = 0;
    int chance = 0;

    cout << "Guess the number (between 1 and 100): ";

    while (true) {
        cin >> guess;
        chance += 1;

        if (guess < randomNumber) {
            cout << "Too low.\nTry again: ";
        } else if (guess > randomNumber) {
            cout << "Too high.\nTry again: ";
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
            break;
        }
    }
    cout<<"Number of attempts = "<<chance;

    return 0;
}


