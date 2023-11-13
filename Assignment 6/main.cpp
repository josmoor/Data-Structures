#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include "hashtable.h"

// Variables

// Functions
std::string toHex(const std::string& value, bool upperCase) {
    std::ostringstream ret;

    for(std::string::size_type i = 0; i < value.length(); i++) {
        ret << std::hex << std::setfill('0') << std::setw(2) << (upperCase ? std::uppercase : std::nouppercase) << (int) value[i];
    }

    return ret.str();
}

int main() {
    std::ifstream file;
    std::string line;
    int * calc[26] = {0};

    file.open("files/Dictionary.txt");

    while(getline(file, line)) {
        // std::cout << line << std::endl;
        std::string value = toHex(line, true);
        *calc[line[0] - 'a']++;
        value = value.substr(0, value.length() - 2);
        std::stringstream strm;
        long output;
        strm << value;
        strm >> std::hex >> output;

        std::cout << output % 200 << std::endl;
        //TODO: Make formula for Hashing, check for collision
    }

    for(int i = 0; i < 26; i++) {
        std::cout << "Numbers [" << i <<"]: " << calc[i] << std::endl;
    }
    return 0;
}