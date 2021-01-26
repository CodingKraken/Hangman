#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "functions.h"
#include <windows.h>

using namespace std;


int main ()
{
    srand ((unsigned) time(0));


    int counter = 0;
    vector<string> wordarr;
    ifstream dict_file("words.txt");
    string line;

    while(getline(dict_file, line))
    {
        string new_line;
        new_line = line + "\n";
        wordarr.push_back(new_line);
    }

    float rfloat;

    rfloat = ((float) rand() / RAND_MAX) * 1000 + 1;

    int rnum =(int) rfloat;
    string word = wordarr[rnum];

    vector<char> wordvec(word.begin(), word.end());

    vector<char> wordhidden;

    for(int i = 0; i < (wordvec.size() - 1); i++) {
        wordhidden.push_back('_');
        cout << wordhidden[i];
    }
    cout << endl;

    cout << word << endl;

    bool has_answered = false;   
    char answer;

    int attempts = 0;

    vector<char> guesses = {' '};

    while(!has_answered) {
        system("cls");
        cout << print_hangman(attempts) << endl;

        cout << printword(wordhidden) << endl;

        string guessed_string(guesses.begin(), guesses.end());
        cout << "\nGuessed Letters: " << guessed_string << endl;

        if(attempts == 6) {
            cout << "Game over!" << endl;
            cout << "\nThe word was: " << word << endl;
            has_answered = true;
            break;
        }
            if(has_won(wordvec, wordhidden)) {
                cout << "You won!\nThe Word was: " << word << endl; 
                has_answered = true;
                break;
        }
        cout << "Attempts Remaining: " << 6 - attempts << endl;
        cout << "Please enter your guess: ";
        cin >> answer;
        cout << endl;
        vector<char> original_wordhidden = wordhidden;
        wordhidden = check_answer(wordvec, wordhidden, answer);
        cout << printword(wordhidden) << endl;
        if(printword(wordhidden) == printword(original_wordhidden)) {
            cout << "Wrong Guess!" << endl;
            attempts++;
            guesses.push_back(answer);
            guesses.push_back(',');
            guesses.push_back(' ');
        } else {
            cout << "Correct Guess!" << endl;
        }
    }
    system("pause");
}