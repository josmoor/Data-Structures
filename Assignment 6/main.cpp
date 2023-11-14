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
        // std::cout << line << std::endl;
        // std::string value = toHex(line, true);
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        calc[hashFunction(line[0])]++;
        words.push_back(line);
        // value = value.substr(0, value.length() - 2);
        // std::stringstream strm;
        // long output;
        // strm << value;
        // strm >> std::hex >> output;

        // std::cout << output % 200 << std::endl;
        //TODO: Make formula for Hashing, check for collision
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

    std::cout << "Your Word: " << userWord << std::endl;

    //TODO: If first letter does not have an array, return 'No Word'... exit program
    //TODO: Else find all similar words based on second letter. If none, return 'did you mean?'
    //TODO: - if yes then display words based on found (if exist, otherwise return 'none')
    //TODO: - else return 'none'

    return 0;
}