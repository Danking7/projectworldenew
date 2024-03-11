#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "implementation.h"

using namespace std;

int main() {
    time_t currentTime = time(0);
    srand(static_cast<unsigned int>(currentTime));

    string guesses = "/Users/reece/Downloads/guesses.txt"; // Path to your word file

    ifstream file(guesses);

    if (!file.is_open()) {
        cout << "Error opening file " << guesses << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    string targetWord = getRandomLine(lines);
    cout << "The word to guess: " << targetWord << endl;

    string guess;
    cout << "Enter your guess: ";
    cin >> guess;

    if (isWordValid(guess, targetWord)) {
        cout << "Congratulations! You guessed the word." << endl;
    }
    else {
        cout << "Sorry, your guess is not correct." << endl;

        // Provide suggestions
        vector<string> suggestions = suggestSimilarWords(guess, lines);
        if (!suggestions.empty()) {
            cout << "Suggestions for similar words:" << endl;
            for (const string& suggestion : suggestions) {
                cout << suggestion << endl;
            }
        }
        else {
            cout << "No similar words found." << endl;
        }
    }

    return 0;
}
