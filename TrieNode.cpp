// File name: Trie.cpp
// Author: Hanchu Shen
// userid: shenh2
// Email: hanchu.shen@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: project10
// Description:  TrieNode class cpp
// Honor statement:I have not given or received unauthorized aid on this assignment.
// Last Changed: 2019/12/4


#include "TrieNode.h"
#include <stdexcept>
#include <iostream>

//constructor
TrieNode::TrieNode(char c, bool b) : character(c),
                                     t(b) {
    for (TrieNodePtr &i : ptr) {
        i = nullptr;
    }
}

//copy constructor
TrieNode::TrieNode(const TrieNode &rhs) : character(rhs.character),
                                          t(rhs.t) {
    for (size_t i = 0; i < NUMBER_OF_CHARS; ++i) {
        if (rhs.ptr[i] != nullptr) {
            ptr[i] = new TrieNode(*rhs.ptr[i]);
        } else {
            ptr[i] = nullptr;
        }
    }
}

//destructor
TrieNode::~TrieNode() {
    for (TrieNodePtr &i : ptr) {
        delete i;
        i = nullptr;
    }
}

//assignment operator
const TrieNode &TrieNode::operator=(const TrieNode &rhs) {
    if (this != &rhs) {
        TrieNode tmp(rhs);
        std::swap(character, tmp.character);
        std::swap(t, tmp.t);
        for (size_t i = 0; i < NUMBER_OF_CHARS; ++i) {
            std::swap(ptr[i], tmp.ptr[i]);
        }
    }
    return *this;
}

//insert
//pre:str is a valid str with all lowercase letters or empty string
void TrieNode::insert(const std::string &str){
    if (str.length() == 0) {
        return;
    } else {
        if (ptr[str[0] - 'a'] == nullptr) {
            ptr[str[0] - 'a'] = new TrieNode(str[0], false);
        }
        if (str.length() == 1) {
            ptr[str[0] - 'a']->t = true;
        }
        return ptr[str[0] - 'a']->insert(str.substr(1));
    }
}

//isWord
//pre:str is a valid str with all lowercase letters or empty string
//post: return true if str is a word, return false otherwise
bool TrieNode::isWord(const std::string &str) const {
    if (ptr[str[0] - 'a'] != nullptr && str.length() > 0) {
        if (str.length() == 1 && ptr[str[0] - 'a']->t) {
            return true;
        } else {
            return ptr[str[0] - 'a']->isWord(str.substr(1));
        }
    } else {
        return false;
    }
}

//isPrefix
//pre:str is a valid str with all lowercase letters or empty string
//post: return true if str is a prefix, return false otherwise
bool TrieNode::isPrefix(const std::string &pre) const {
    if (pre.length() == 0) {
        return true;
    } else if (ptr[pre[0] - 'a'] != nullptr) {
        return ptr[pre[0] - 'a']->isPrefix(pre.substr(1));
    } else {
        return false;
    }
}

//print
//pre:str is a valid str with all lowercase letters or empty string
void TrieNode::print(const std::string &str) const {
    if (t) {
        std::cout << str << std::endl;
    }
    for (auto &i : ptr) {
        if (i != nullptr) {
            i->print(str + i->character);
        }
    }
}
