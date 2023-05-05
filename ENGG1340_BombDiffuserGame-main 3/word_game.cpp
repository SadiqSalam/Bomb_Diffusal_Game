#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <algorithm>
#include "word_game.h"
#include "time.h"
using namespace std;

int select_main_word(string words[6][15], string &main_word){
    int random = rand()%5; //generate a random number between 0 and 5
    main_word = words[random][0]; //use the random number to select a random word from column 1 of the 2d array
    return random; // return the word. this will be the "main_word".
} //the index of the main_word is returned as main_index, to makeit easier to code

void select_words(string words[6][15], string &word1, string &word2, string &word3, string &word4, string &word5, string &word6){
    int a[6] = {0,1,2,3,4,5};
    int b[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14}; //where elements from a and b are in the form words[a][b]
    random_shuffle(a, a + 6); //the two arrays "a","b" with the indices are randomly shuffled
    random_shuffle(b, b + 13);
    word1 = words[a[0]][b[0]]; //6 words are randomly selected from each row
    word2 = words[a[1]][b[1]];
    word3 = words[a[2]][b[2]];
    word4 = words[a[3]][b[3]];
    word5 = words[a[4]][b[4]];
    word6 = words[a[5]][b[5]];

}

void print_ui(string main_word, string word1, string word2, string word3, string word4, string word5, string word6){
    cout << "┏━━━━━━━━━━━━━━━━┓" << endl; //a fancy way to display everything
    cout << "┃" << "     " << main_word << "      " << "┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━┛" << endl;
    cout << "┏━━━━━━━┓┏━━━━━━━┓" << endl;
    cout << "┃" << " " << word1 << " " << "┃" << "┃" << " " << word2 << " " << "┃" << endl;
    cout << "┗━━━━━━━┛┗━━━━━━━┛" << endl;
    cout << "┏━━━━━━━┓┏━━━━━━━┓" << endl;
    cout << "┃" << " " << word3 << " " << "┃" << "┃" << " " << word4 << " " << "┃" << endl;
    cout << "┗━━━━━━━┛┗━━━━━━━┛" << endl;
    cout << "┏━━━━━━━┓┏━━━━━━━┓" << endl;
    cout << "┃" << " " << word5 << " " << "┃" << "┃" << " " << word6 << " " << "┃" << endl;
    cout << "┗━━━━━━━┛┗━━━━━━━┛" << endl;
}


string find_word(string words[6][15], int main_index, string main_word, string word1, string word2, string word3, string word4, string word5, string word6){
    string answer; //this function is used to find the correct answer for the puzzle. the correct answer is then stored in the variable answer
    for (int i = 0; i < 15; i++){ //main_index allows to directly access the correct row from where
        if (words[main_index][i] == word1){ // to loop through every element of the corresponding row
            return word1; //the first word to be matched is immediately returned
        }else if (words[main_index][i] == word2){
            return word2;
        }else if (words[main_index][i] == word3){
            return word3;
        }else if (words[main_index][i] == word4){
            return word4;
        }else if (words[main_index][i] == word5){
            return word5;
        }else if (words[main_index][i] == word6){
            return word6;
        }
    }
    return ""; //there was a compilation error, so this statement was added
}

bool check_word(string answer, string user_word){
    return (answer == user_word); //this function checks if the user input matches the correct answer
}
int word_game(chrono::steady_clock::time_point& end_time){
    while (chrono::steady_clock::now() < end_time) {
        //create list of words in an array with 14 columns and 6 rows
        string words[6][15] = {{"FLUTE", "PAUSE", "SPARK", "SMOKE", "TIMER", "WRONG", "PRESS", "LOOSE", "THINK", "FLUTE", "BURNT", "FIRST", "UHH:(", "HELP!", "WAIT!"},
                               {"FIRST", "WRONG", "SPARK", "PAUSE", "TIMER", "BURNT", "LOOSE", "HELP!", "UHH:(", "WAIT!", "FLUTE", "THINK", "SMOKE", "PRESS", "FIRST"},
                               {"BURNT", "THINK", "UHH:(", "WAIT!", "FIRST", "SMOKE", "FLUTE", "LOOSE", "PAUSE", "HELP!", "WRONG", "PRESS", "SPARK", "BURNT", "TIMER"},
                               {"THINK", "WAIT!", "LOOSE", "SPARK", "TIMER", "THINK", "PRESS", "FLUTE", "HELP!", "BURNT", "SMOKE", "WRONG", "UHH:(", "PAUSE", "FIRST"},
                               {"THING", "UHH:(", "LOOSE", "SPARK", "TIMER", "PAUSE", "THINK", "BURNT", "PRESS", "WRONG", "SMOKE", "WAIT!", "FIRST", "HELP!", "FLUTE"},
                               {"PAUSE", "SPARK", "LOOSE", "UHH:(", "TIMER", "FIRST", "SMOKE", "PRESS", "FLUTE", "HELP!", "PAUSE", "WRONG", "THINK", "BURNT", "WAIT!"}};
        //initialise all the variables
        string main_word, word1, word2, word3, word4, word5, word6, answer, user_word;
        int main_index;

        srand((unsigned) time(NULL)); //generate a seed

        main_index = select_main_word(words, main_word); //index of the array corresponding to row of main_word
        select_words(words, word1, word2, word3, word4, word5,
                     word6); //randomly select 6 words from each row and store in 6 variables
        answer = find_word(words, main_index, main_word, word1, word2, word3, word4, word5,
                           word6); //find the correct answer for the puzzle
        print_ui(main_word, word1, word2, word3, word4, word5, word6); //print the ui
        cout << "Enter word: "; //prompt for ui
        cin >> user_word; //store user input in user_word variable
        cout << endl;

        while (chrono::steady_clock::now() < end_time && !check_word(answer, user_word)) { //keep on looping till user input is correct or till time runs out
            cout << "Wrong 5 seconds deducted" << endl;
            end_time -= chrono::seconds(5);
            auto remaining_time = chrono::duration_cast<chrono::seconds>(end_time - chrono::steady_clock::now());
            cout << "Time remaining: " << remaining_time.count() << " seconds" << endl;

            print_ui(main_word, word1, word2, word3, word4, word5, word6);
            cout << "Enter word: ";
            cin >> user_word;
            cout << endl;
        }
        if(chrono::steady_clock::now() < end_time){

            cout << "YOU WIN THIS ROUND!" << endl;
            auto remaining_time = chrono::duration_cast<chrono::seconds>(end_time - chrono::steady_clock::now());
            cout << "Time remaining: " << remaining_time.count() << " seconds" << endl;
            return 1; //since function return type is int
        }
    }

    return 0;
}

