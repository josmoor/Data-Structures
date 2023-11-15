#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>

#include<algorithm>
#include<cctype>

#include "hash.h"

// Variables

// Functions
// std::string toHex(const std::string& value, bool upperCase) {
//     std::ostringstream ret;

//     for(std::string::size_type i = 0; i < value.length(); i++) {
//         ret << std::hex << std::setfill('0') << std::setw(2) << (upperCase ? std::uppercase : std::nouppercase) << (int) value[i];
//     }

//     return ret.str();
// }

int main() {
    std::ifstream file;
    std::string line;
    std::string userWord;

    Hashtable * table = new Hashtable();
    std::vector<std::string> words;

    short calc[26] = {0};

    file.open("files/Dictionary.txt");

    while(getline(file, line)) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        calc[hashFunction(line[0])]++;
        words.push_back(line);
    }

    for(int i = 0; i < 26; i++) {
       table->createHashObjectArray(i, calc[i]);
    }

    for(int i = 0; i < words.size(); i++) {
        std::string toAdd = words.back();
        std::transform(toAdd.begin(), toAdd.end(), toAdd.begin(), ::tolower);

        table->addWord(toAdd);
        words.pop_back();
    }

    std::cout << "Enter a word (No Spaces | Must be at least ONE character): ";
    std::cin >> userWord;
    std::transform(userWord.begin(), userWord.end(), userWord.begin(), ::tolower);

    std::vector<std::string> collection = table->getWords(userWord);
    std::string correct = table->getSuggestion(hashFunction(userWord[0]));

    if(collection.size() == 0) {
        std::cout << "Possible misspell, did you mean?: " << table->getSuggestion(hashFunction(userWord[0])) << std::endl;
        std::string answer;
        std::cin >> answer;

        if(answer == "yes") {
            std::transform(correct.begin(), correct.end(), correct.begin(), ::tolower);
            collection = table->getWords(correct);
            
            while(collection.size() > 0) {
                std::cout << collection.back() << std::endl;
                collection.pop_back();
            }
        } else
            std::cout << "No words found." << std::endl;

    } else {
        while(collection.size() > 0) {
            std::cout << collection.back() << std::endl;
            collection.pop_back();
        }
    }

    return 0;
}