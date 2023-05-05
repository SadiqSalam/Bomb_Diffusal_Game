#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "leaderboard.h"
//vector is used for dynamic memory management
using namespace std;

void print_leaderboard(vector <Entry> &info){ //print leaderboard at the end
    int rank = 1; //initialise rank to be 1
    int column1 = 10, column2 = 20, column3 = 10; //set column width
    //cout << left << setw(column1) << "Rank" << setw(column2) << "Name" << setw(column3) << "Score" << endl;
    cout << left << setw(column1) << "Rank" << "┃" << setw(column2) << "Name" << "┃" << setw(column3) << "Score" << endl; //ui for leaderboard
    for (int i = 0; i < 50; i++) cout << "━"; 
    cout << endl;
    for (auto itr = info.end() - 1; itr >= info.begin(); itr--){
        cout << left << setw(column1) << rank << "┃" << setw(column2) << (*itr).name << "┃" << setw(column3) << (*itr).score << endl;
        rank++;
    }
}

void load_save(vector <Entry> &info){ //read save data from file at beginning of program
    string line;
    Entry data;
    cout << "Text file save.txt from same directory would be loaded!" << endl;
    cout << "If using custom save file please rename as save.txt and place in the same directory!" << endl;
    ofstream fout;
    
    string x;
    cout << "Do you want to reset leaderboard? (y/n) *case-sensitive*" << endl;
    cin >> x;

    if (x == "y"){
        fout.open("save.txt"); //reset leaderboad
    } else {
        fout.open("save.txt", ios::app); //don't reset leaderboard. also create new file if save.txt not present
    }
    fout.close();

    ifstream fin; 
    fin.open("save.txt");
    if (fin.fail()){
        cout << "Error opening save file!" << endl;
    }else{
        while (getline(fin, line)){
            istringstream iss(line); //use string stream object for easier data manipulation
            iss >> data.name >> data.score;
            info.push_back(data); 
        }
    }
    fin.close();
    sort(info.begin(), info.end());//sort leaderboard
}

void write_save(vector <Entry> &info){ //write save data to file at end of program
    sort(info.begin(), info.end());
    ofstream fout;
    fout.open("save.txt");
    if (fout.fail()){
        cout << "Error opening save file!" << endl;
    }else{
        for (auto itr = info.begin(); itr < info.end(); itr++){
            fout << (*itr).name << " " << (*itr).score << endl;
        }
    }
    fout.close();
}

void new_entry(vector <Entry> &info, Entry entry){ //add new time returned at the end
    info.push_back(entry);
    sort(info.begin(), info.end()); //sort leaderboard. done multiple times to avoid any errors when displaying leaderboard
}
