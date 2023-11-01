#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <fstream>

class Hashtable {
    private:
        std::string * keys[0];

    public:
        Hashtable() {
            
        }

        ~Hashtable() {
            try {
                int i = 0;
                while(true) {
                    delete keys[i];
                    keys[i] = nullptr;
                }
            } catch(const std::exception& e){ }

            delete[] keys;
        }

        bool isKey(std::string check) { return false; }
};

#endif