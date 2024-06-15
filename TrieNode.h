// File name: Trie.cpp
// Author: Hanchu Shen
// userid: shenh2
// Email: hanchu.shen@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: project10
// Description:  TrieNode class header
// Honor statement:I have not given or received unauthorized aid on this assignment.
// Last Changed: 2019/12/4


#ifndef PROJECT9_TRIENODE_H
#define PROJECT9_TRIENODE_H

#include <cstddef>
#include <stdexcept>

const size_t NUMBER_OF_CHARS = 26;//number of lower-case alphabetic characters

class TrieNode {
    typedef TrieNode *TrieNodePtr;
private:
    char character;//char value stored in each node
    bool t;//boolean vector to indicate whether it is the end of a word
    TrieNodePtr ptr[NUMBER_OF_CHARS];//array of TrieNode pointer represents 26 letters

public:
    //constructor
    TrieNode(char c, bool b);

    //copy constructor
    TrieNode(const TrieNode &rhs);

    //destructor
    ~TrieNode();

    //assignment operator
    const TrieNode &operator=(const TrieNode &rhs);

    //insert
    //pre:str is a valid str with all lowercase letters or empty string
    void insert(const std::string &str);

    //isWord
    //pre:str is a valid str with all lowercase letters or empty string
    //post: return true if str is a word, return false otherwise
    bool isWord(const std::string &str) const;

    //isPrefix
    //pre:str is a valid str with all lowercase letters or empty string
    //post: return true if str is a prefix, return false otherwise
    bool isPrefix(const std::string &pre) const;

    //print
    //pre:str is a valid str with all lowercase letters or empty string
    void print(const std::string &str) const;

};


#endif //PROJECT9_TRIENODE_H
