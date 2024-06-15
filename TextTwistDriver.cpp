// File name: TextTwistDriver.cpp
// Author: Hanchu Shen
// userid: shenh2
// Email: hanchu.shen@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: project10
// Description:  TextTwistDriver
// Honor statement:I have not given or received unauthorized aid on this assignment.
// Last Changed: 2019/12/4


#include <iostream>
#include "TextTwist.h"

const std::string DICTIONARY = "ospd.txt";//file name of the lexicon of acceptable words

int main() {
    std::string choice;
    //Initialization and load a lexicon of acceptable words
    std::cout << "Loading valid words. Please wait..." << std::endl;
    std::string fin = DICTIONARY;
    Trie dic;
    dic.loadFromFile(fin);
    std::cout << "\n\nWelcome to the TEXT TWIST Solver.\n\n" << std::endl;
    do {
        //doing TextTwist game
        TextTwist game;
        game.getLetters();
        game.addWords(dic);
        game.printWords();
        //ask the user if they want to run the program again
        std::cout << "\nDo you want to solve another maze? (Y|N)" << std::endl;
        std::cin >> choice;
    } while (choice.at(0) == 'Y' || choice.at(0) == 'y');

    return 0;
}