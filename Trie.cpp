// File name: Trie.cpp
// Author: Hanchu Shen
// userid: shenh2
// Email: hanchu.shen@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: project10
// Description:  Trie class cpp
// Honor statement:I have not given or received unauthorized aid on this assignment.
// Last Changed: 2019/12/4


#include <fstream>
#include <iostream>
#include "Trie.h"

//constructor
Trie::Trie() : myRoot(TrieNode(' ', false)),
               count(0) {}

//insert
//pre:str is a valid str with all lowercase letters or empty string
void Trie::insert(const std::string &word){
    if (word.length() > 0 && !isWord(word)) {
        myRoot.insert(word);
        count++;
    }
}

//loadFromFile
//pre: word is a valid string
void Trie::loadFromFile(const std::string &word) {
    std::string str;
    std::ifstream file(word.c_str());
    if (!file) {//check validity of input file
        throw std::invalid_argument("Error opening input file: "+word);
    }
    while (file>>str) {//construct WordSet
        insert(str);
    }
    file.close();
}

//isWord
//pre:str is a valid str with all lowercase letters or empty string
//post: return true if str is a word, return false otherwise
bool Trie::isWord(const std::string &word) const {
    return myRoot.isWord(word);
}

//isPrefix
//pre:str is a valid str with all lowercase letters or empty string
//post: return true if str is a prefix, return false otherwise
bool Trie::isPrefix(const std::string &pre) const {
    return myRoot.isPrefix(pre);
}

//print
//print all words in Trie object
void Trie::print() const {
    myRoot.print("");
}

//wordCount
//post: return current number of words in Trie object
size_t Trie::wordCount() const {
    return count;
}