#include "implementation.h"

#include <iostream>
#include <fstream>
#include "implementation.h"
#include <algorithm>

bool isWordValid(const std::string& word, const std::string& targetWord) {
    // Assuming both words are of the same length
    if (word.size() != targetWord.size())
        return false;

    // Word is valid if each character is in the same position as in the target word
    for (size_t i = 0; i < word.size(); ++i) {
        if (word[i] != targetWord[i] && targetWord.find(word[i]) == std::string::npos)
            return false;
    }

    return true;
}

std::vector<std::string> suggestSimilarWords(const std::string& word, const std::vector<std::string>& dictionary) {
    std::vector<std::string> suggestions;
    for (const std::string& dictWord : dictionary) {
        if (isWordValid(dictWord, word)) {
            suggestions.push_back(dictWord);
        }
    }
    return suggestions;
}
