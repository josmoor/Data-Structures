#ifndef HASH_H
#define HASH_H

#include <string>
#include <fstream>

class Hashtable;

int hashFunction(char c) { return c - 'a'; }

class HashObjects {
    private:
        std::string * key;
        int size;
    public:
        HashObjects() { }

        HashObjects(int size) {
            key = new std::string[size];
            this->size = size;
        }

        ~HashObjects() {
            for(int i = 0; i < key->length(); i++)
                key[i] = nullptr;

            delete[] key;
        }

        std::string * getKeys() { return key; }

        void addWord(int hashLoc, std::string word) {
            while(true) {
                if(hashLoc >= size)
                    hashLoc -= size;

                if(key[hashLoc] != "") {
                    hashLoc++;
                } else {
                    key[hashLoc] = word;
                    break;
                }
            }
        }
};

class Hashtable {
    private:
        HashObjects * words; 
    public:
        Hashtable() {
            words = new HashObjects[26];
        }

        ~Hashtable() {
            for(int i = 0; i < 26; i++) {
                words[i].~HashObjects();
            }

            delete[] words;
        }

        void createHashObjectArray(int hashLoc, int size) {
            words[hashLoc] = * new HashObjects(size);
        }

        void addWord(std::string word) {
            int hashLoc = hashFunction(word[0]);
            int hashLocInner = hashFunction(word.length() > 1 ? word[1] : word[0]);

            //TODO: hashLocInner is giving a negative number (i is being treated as I).

            words[hashLoc].addWord(hashLocInner, word);
        }
};

#endif