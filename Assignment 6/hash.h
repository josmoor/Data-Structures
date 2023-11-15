#ifndef HASH_H
#define HASH_H

#include <string>
#include <fstream>
#include<vector>

class Hashtable;

int hashFunction(char c) { return c - 'a'; }

class HashObjects {
    private:
        std::string * key;
        std::string suggestion;
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

        std::vector<std::string> getWords(char c) {
            std::vector<std::string> ret = * new std::vector<std::string>();
            suggestion = key[0];

            for(int i = 0; i < size; i++) {
                char keyChar = key[i].length() > 1 && key[i][1] != ' ' ? key[i][1] : key[i][0];

                if(c == keyChar) {
                    ret.push_back(key[i]);
                }
            }

            return ret;
        }

        std::string getSuggestion() { return suggestion; }

        void addWord(int hashLoc, std::string word) {
            while(true) {
                if(hashLoc >= size)
                    hashLoc = 0;

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
            int hashLocInner = hashFunction(word.length() > 1 && word[1] != ' ' ? word[0] : word[1]);

            words[hashLoc].addWord(hashLocInner, word);
        }

        std::vector<std::string> getWords(std::string userWord) {
            return words[hashFunction(userWord[0])].getWords(userWord.length() > 1 && userWord[1] != ' ' ? userWord[1] : userWord[0]);
        }

        std::string getSuggestion(int hashLoc) { return words[hashLoc].getSuggestion(); }
};

#endif