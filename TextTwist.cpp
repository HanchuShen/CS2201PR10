// File name: TextTwist.cpp
// Author: Hanchu Shen
// userid: shenh2
// Email: hanchu.shen@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: project10
// Description:  TextTwist class cpp
// Honor statement:I have not given or received unauthorized aid on this assignment.
// Last Changed: 2019/12/4


#include "TextTwist.h"
#include <iostream>
#include <cstring>

//default constructor
TextTwist::TextTwist() {
}

//getLetters
//prompt user to input certain number of chars and store this valid
//string into an array of chars in alphabetic order
void TextTwist::getLetters() {
    std::string userString;
    do {//keep prompting user to input string of chars until a valid string is received
        std::cout << "Enter the 7 letters of the TEXT TWIST game:" << std::endl;
        std::cin >> userString;
    } while (!validString(userString));
    sortLetters(userString);//sort user's valid string in alphabetic order
    for (size_t i = 0; i < NUMBER_OF_LETTERS; ++i) {//store user's string into array of chars
        letters[i] = userString[i];
    }
}

//validString
//pre: word is an non-empty string
//post: return a boolean value of true if the string is an all-lower-case
//alphabetic string of certain length; return false otherwise
bool TextTwist::validString(const std::string &string) {
    if (string.length() != NUMBER_OF_LETTERS) {//check if the string is of certain length
        std::cout << "You must enter exactly 7 characters.\n\n" << std::endl;
        return false;
    } else if (!isLowerAlpha(string)) {//check if the string is lower-case alphabetic
        std::cout << "You must enter only lower case alphabetic characters.\n\n" << std::endl;
        return false;
    }
    return true;
}

//isLowerAlpha
//pre: word is an non-empty string
//post: return a boolean value of true if all chars in the string are
//lower-case alphabetic characters; return false otherwise
bool TextTwist::isLowerAlpha(const std::string &string) const {
    for (char i: string) {//check if the each char of the string is lower-case alphabetic
        if (isalpha(i) == 0 || islower(i) == 0) {
            return false;
        }
    }
    return true;
}

//sortLetters
//sort a string in alphabetic order
//pre: string is a valid all-lower-case alphabetic string
void TextTwist::sortLetters(const std::string &string) {
    bool sorted = false;//use bubble sort to sort the string in alphabetic order
    for (size_t i = 0; i < NUMBER_OF_LETTERS - 1 && !sorted; ++i) {
        sorted = true;
        for (size_t j = 0; j < NUMBER_OF_LETTERS - i - 1; ++j) {
            if (string[j] > string[j + 1]) {
                std::swap(letters[j], letters[j + 1]);
                sorted = false;
            }
        }
    }
}

//addWords
//using user's valid characters to combine and add valid words
//pre: Trie is a valid Trie object(should be the Trie ofa lexicon of
//acceptable words)loaded before
void TextTwist::addWords(const Trie &dic) {
    char pre = ' ';//this char is the last char used as the first letter of combinations
    std::string chars;//this string represent a collection of currently unused chars
    for (char letter : letters) {//get a string of user's chars
        chars += letter;
    }
    for (size_t i = 0; i < NUMBER_OF_LETTERS; ++i) {//use each of user's chars as first letter of combos
        if (letters[i] != pre) {//start combining only if current first char is different from previous one
            pre = letters[i];
            std::string initialChar;
            initialChar = letters[i];//a string of first char used as parameter in combineLetters
            combineLetters(initialChar, chars.substr(0, i) + chars.substr(i + 1), dic);
        }
    }
}

//combineLetters
//start with a string and append new unused user characters to
//create now combinations of words
//pre: comb is an non-empty string; characters is a string storing remaining
//unused user character(is also an array of characters);Trie is a valid Trie object
//(should be the Trie ofa lexicon of acceptable words)loaded before
void TextTwist::combineLetters(const std::string &comb, std::string chars, const Trie &dic) {
    if (dic.isPrefix(comb)) {//if current word is valid prefix, check and add it to words
        addWord(comb, dic);
        //append all possible unused chars to this prefix to create new combos
        for (size_t i = 0; i < chars.length(); ++i) {
            combineLetters(comb + chars[i], chars.substr(0, i) + chars.substr(i + 1), dic);
        }
    }
}

//addWord
//receive a string and add it to the Trie object of words;do nothing otherwise
//pre: word is an-nonempty string; Trie is a valid Trie object
//(should be the Trie ofa lexicon of acceptable words)loaded before
void TextTwist::addWord(const std::string &word, const Trie &dic) {
    //check if the word is over length and valid in dictionary
    if (word.length() >= 3 && dic.isWord(word) && !words.isWord(word)) {
        words.insert(word);
    }
}

//printWords
//print all words in words Trie object
void TextTwist::printWords() {
    words.print();
}




