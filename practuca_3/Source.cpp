#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

// Function to remove all occurrences of words from the second text
std::string removeWords(const std::string& firstText, const std::string& secondText) {
    std::vector<std::string> words;
    std::istringstream iss(firstText);
    std::string word;

    // Split the first text into individual words
    while (iss >> word) {
        words.push_back(word);
    }

    // Remove words from the second text
    std::istringstream iss2(secondText);
    std::ostringstream oss;
    std::string currentWord;

    while (iss2 >> currentWord) {
        // Remove punctuation marks from the current word
        currentWord.erase(std::remove_if(currentWord.begin(), currentWord.end(), ::ispunct), currentWord.end());

        // Check if the modified word belongs to the first text
        auto it = std::find_if(words.begin(), words.end(), [&](const std::string& w) {
            std::string tempWord = w;
            tempWord.erase(std::remove_if(tempWord.begin(), tempWord.end(), ::ispunct), tempWord.end());
            return tempWord == currentWord;
            });

        if (it == words.end()) {
            oss << currentWord << " ";
        }
    }

    return oss.str();
}

int main() {
    std::cout << "Enter the first text: ";
    std::string firstText;
    std::getline(std::cin, firstText);

    std::cout << "Enter the second text: ";
    std::string secondText;
    std::getline(std::cin, secondText);

    std::string result = removeWords(firstText, secondText);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
