#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <string>
#include <vector> 

std::string getRandomLine(const std::vector<std::string>& lines);
bool isWordValid(const std::string& word, const std::string& targetWord);
std::vector<std::string> suggestSimilarWords(const std::string& word, const std::vector<std::string>& dictionary);

#endif // IMPLEMENTATION_H