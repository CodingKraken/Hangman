#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> check_answer(vector<char> word, vector<char> hiddenword, char answer);
string printword(vector<char> word);
bool has_won(vector<char>word, vector<char> hiddenword);
string print_hangman(int attempts);