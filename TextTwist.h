// File name: TextTwist.h
// Author: Hanchu Shen
// userid: shenh2
// Email: hanchu.shen@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: project10
// Description:  TextTwist class header
// Honor statement:I have not given or received unauthorized aid on this assignment.
// Last Changed: 2019/12/4


#ifndef PROJECT10_TEXTTWIST_H
#define PROJECT10_TEXTTWIST_H

#include "Trie.h"
#include <stdexcept>

const size_t NUMBER_OF_LETTERS = 7;

class TextTwist {
private:
    char letters[NUMBER_OF_LETTERS];//array storing certain number of valid user's input chars
    Trie words;//a Trie class storing all possible words by combining user's chars
public:
    //default constructor
    TextTwist();

    //getLetters
    //prompt user to input certain number of chars and store this valid
    //string into an array of chars in alphabetic order
    void getLetters();

    //validString
    //pre: word is an non-empty string
    //post: return a boolean value of true if the string is an all-lower-case
    //alphabetic string of certain length; return false otherwise
    bool validString(const std::string &word);

    //isLowerAlpha
    //pre: word is an non-empty string
    //post: return a boolean value of true if all chars in the string are
    //lower-case alphabetic characters; return false otherwise
    bool isLowerAlpha(const std::string &word) const;

    //sortLetters
    //sort a string in alphabetic order
    //pre: string is a valid all-lower-case alphabetic string
    void sortLetters(const std::string &string);

    //addWords
    //using user's valid characters to combine and add valid words
    //pre: Trie is a valid Trie object(should be the Trie ofa lexicon of
    //acceptable words)loaded before
    void addWords(const Trie &dic);

    //combineLetters
    //start with a string and append new unused user characters to
    //create now combinations of words
    //pre: comb is an non-empty string; characters is a string storing remaining
    //unused user character(is also an array of characters);Trie is a valid Trie object
    //(should be the Trie ofa lexicon of acceptable words)loaded before
    void combineLetters(const std::string &comb, std::string characters, const Trie &dic);

    //addWord
    //receive a string and add it to the Trie object of words;do nothing otherwise
    //pre: word is an-nonempty string; Trie is a valid Trie object
    //(should be the Trie ofa lexicon of acceptable words)loaded before
    void addWord(const std::string &word, const Trie &dic);

    //printWords
    //print all words in words Trie object
    void printWords();
};


#endif //PROJECT10_TEXTTWIST_H
