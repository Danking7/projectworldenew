
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "implementation.hpp"

using namespace std;

    int main() {
        time_t currentTime = time(0);
            srand(static_cast<unsigned int>(currentTime));
        
        string guesses = "/Users/Danking/Downloads/guesses.txt";
        
      
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
        
        string randomLine = getRandomLine(lines);
        cout << randomLine << endl;
        
        return 0;
    }

