#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<char> check_answer(vector<char> word, vector<char> hiddenword, char answer ) {
    for(int i = 0; i < (word.size() - 1); i++) {
        if(word[i] == answer) {
            hiddenword.at(i) = (char)answer;
        }
    }

    return hiddenword;
}



string printword(vector<char> word) {
    string output_word(word.begin(), word.end());
    return output_word;
}

bool has_won(vector<char> word, vector<char> hiddenword) {
    int correcthits = 0;
    for(int i = 0; i < (word.size() - 1); i++) {
        if(word[i] == hiddenword[i]) {
            correcthits++;
        }
    }
    if(correcthits == word.size() - 1) {
        return true;
    } else {
        return false;
    }
}

string print_hangman(int attempts) {
    string hangman;
    switch(attempts) {
        case 0:
            hangman = "  +---+ \n  |   |\n      |\n      |\n      |\n      |\n========";
            break;
        case 1:
            hangman = "  +---+ \n  |   |\n  O   |\n      |\n      |\n      |\n========";
            break;
        case 2:
            hangman = "  +---+ \n  |   |\n  O   |\n  |   |\n      |\n      |\n========";
            break;
        case 3:
            hangman = "  +---+ \n  |   |\n  O   |\n /|   |\n      |\n      |\n========";
            break;
        case 4:
            hangman = "  +---+ \n  |   |\n  O   |\n /|\\  |\n      |\n      |\n========";
            break;
        case 5:
            hangman = "  +---+ \n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n========";
            break;
        case 6:
            hangman = "  +---+ \n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========";
            break;
    }

    return hangman;
}