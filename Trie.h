// File name: Trie.h
// Author: Hanchu Shen
// userid: shenh2
// Email: hanchu.shen@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: project10
// Description:  Trie class header
// Honor statement:I have not given or received unauthorized aid on this assignment.
// Last Changed: 2019/12/4


#ifndef PROJECT9_TRIE_H
#define PROJECT9_TRIE_H

#include <stdexcept>
#include "TrieNode.h"

class Trie {
private:
    TrieNode myRoot;//root TrieNode object in Trie
    size_t count;//count of words in Trie
public:
    //constructor
    Trie();

    //insert
    //pre:str is a valid str with all lowercase letters or empty string
    void insert(const std::string &word);

    //loadFromFile
    //pre: word is a valid string
    void loadFromFile(const std::string &word);

    //isWord
    //pre:str is a valid str with all lowercase letters or empty string
    //post: return true if str is a word, return false otherwise
    bool isWord(const std::string &word) const;

    //isPrefix
    //pre:str is a valid str with all lowercase letters or empty string
    //post: return true if str is a prefix, return false otherwise
    bool isPrefix(const std::string &pre) const;

    //print
    //print all words in Trie object
    void print() const;

    //wordCount
    //post: return current number of words in Trie object
    size_t wordCount() const;

};


#endif //PROJECT9_TRIE_H
