#include "symbolCombi.h"
#include "word_game.h"
#include "leaderboard.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "cut_wire.h"
#include "number_game.h"
#include "time.h"

using namespace std;

void start_game(vector <Entry> &info){
    cout << "loading save data...";
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;
    load_save(info);
}

void end_game(vector <Entry> &info, int score){
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl;
    Entry entry = {name, score};
    new_entry(info, entry);
    write_save(info);
    print_leaderboard(info);

}

int main(){

    vector <Entry> info; //declare vector for leaderboard
    int score; //from timer

    start_game(info);
    auto start_time = chrono::steady_clock::now();
    auto end_time = start_time + chrono::seconds(120);
    cout << R"(
   ___  _ ______             ___       ___             __
  / _ \(_) _/ _/_ _____ ___ / _ \___ _/ _ )___  __ _  / /
 / // / / _/ _/ // (_-</ -_) // / _ `/ _  / _ \/  ' \/ _ \
/____/_/_//_/ \_,_/___/\__/____/\_,_/____/\___/_/_/_/_.__/
                                                          )"<<endl;
    while (chrono::steady_clock::now() < end_time) {
        this_thread::sleep_for(chrono::milliseconds(10));
        //add game implementation
        // word_game();
        //number_game();
        //cut_wire();

        if (number_game(end_time) == 0) {
            // Time's up, terminate the program
            cout << "GAME OVER" << endl;
            cout << "You have run out of time." << endl;
            return 1;
        }
        cout << "************************************" << endl;
        if (symbol(end_time) == 0) {
            // Time's up, terminate the program
            cout << "GAME OVER" << endl;
            cout << "You have run out of time." << endl;
            return 1;
        }
        cout << "************************************" << endl;
        if (word_game(end_time) == 0) {
            // Time's up, terminate the program
            cout << "GAME OVER" << endl;
            cout << "You have run out of time." << endl;
            return 1;
        }
        cout << "************************************" << endl;
        if (cut_wire(end_time) == 0) {
            // Time's up, terminate the program
            cout << "GAME OVER" << endl;
            cout << "You have run out of time." << endl;
            return 1;
        }
        cout << "************************************" << endl;
        auto remaining_time = chrono::duration_cast<chrono::seconds>(end_time - chrono::steady_clock::now());
        score=remaining_time.count();
        end_game(info, score);

        return 1;
    }

}