
// word_game.h
#ifndef WORD_GAME_H
#define WORD_GAME_H

#include <string>
#include "time.h"
using namespace std;

int select_main_word(string words[6][15], string &main_word); //randomly select word from first column of "words" array and assign to variable with reference

void select_words(string words[6][15], string &word1, string &word2, string &word3, string &word4, string &word5, string &word6); //select 6 random words from "words" array and assign them to a variable using a reference

void print_ui(string main_word, string word1, string word2, string word3, string word4, string word5, string word6); //print the user interface


string find_word(string words[6][15], int main_index, string main_word, string word1, string word2, string word3, string word4, string word5, string word6); //find the correct answer for the puzzle

bool check_word(string answer, string user_word); //check if the word entered by the user is correct

int word_game(chrono::steady_clock::time_point& end_time);


#endif
