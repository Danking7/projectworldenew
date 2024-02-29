//
//  implementation.cpp
//  projectworldenew
//
//  Created by Dan King on 29/02/2024.
//

#include "implementation.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string getRandomLine(const vector<string>& lines) {
    if (lines.empty())
        return "File is empty";
    
    int randomIndex = rand() % lines.size();
    return lines[randomIndex];
}
