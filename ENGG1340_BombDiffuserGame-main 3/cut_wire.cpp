// Wire Module

#include "time.h"
#include "cut_wire.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

int check_wires(string wires[],int n){
//	Number of each color.
    int yellow=0,white=0,black=0,red=0,blue=0;
    for (int i=0;i<n;i++){
        if(wires[i]=="Red"){
            red++;
        }
        else if(wires[i]=="Yellow"){
            yellow++;
        }
        else if(wires[i]=="Black"){
            black++;
        }
        else if(wires[i]=="Blue"){
            blue++;
        }
        else if(wires[i]=="White"){
            white++;
        }
    }

    //	4 wires
    if(n==4){
        //	More than 1 red wire. Cut the last red wire.
        if(red>1){
            int last_red;
            for(int i=n-1;i>=0;i--){
                if (wires[i]=="Red"){
                    last_red=i;
                    break;
                }
            }
            return last_red+1;
        }
        //	Last wire is yellow. Cut the 1st wire.
        if(wires[n-1]=="Yellow" && red==0){
            return 1;
        }
        //	Only one blue wire. Cut the 3rd wire.
        if(blue==1){
            return 3;
        }
        //	More than one yellow wire. Cut the last wire.
        if(yellow>1){
            return 4;
        }
        //	Otherwise, cut the 2nd wire.
        return 2;
    }

    //	5 wires
    if(n==5){
        //	Last wire is black. Cut the 4th wire.
        if (wires[4]=="Black"){
            return 4;
        }
        //	Otherwise, only one red wire && more than one yellow wire. Cut the 1st wire.
        if(red==1&&yellow>1){
            return 1;
        }
        //	Otherwise, no black wire. Cut the 2nd wire.
        if(black==0){
            return 2;
        }
        //	Otherwise, Cut the 1st wire.
        return 1;
    }

    //	6 wires
    if (n==6){
        //	No yellow wire. Cut the 3rd wire.
        if (yellow==0){
            return 3;
        }
        //	Otherwise, only one yellow wire && more than one white wire. Cut the 4th wire.
        if(yellow==0&&white>1){
            return 4;
        }
        //	Otherwise, no red wire. Cut the last wire.
        if(red==0){
            return 6;
        }
        // Otherwise, cut the 4th wire.
        return 4;
    }
    return 0;
}


int cut_wire(chrono::steady_clock::time_point& end_time){
    while (chrono::steady_clock::now() < end_time) {
        srand(time(0));
        // Wires have 5 colors, Red(1) White(2) Black(3) Yellow(4) Blue(5). Five situations, 3 wires, 4 wires, 5 wires, and 6 wires.
        unordered_map<int, string> wire;
        wire = {{1, "Red"},
                {2, "White"},
                {3, "Black"},
                {4, "Yellow"},
                {5, "Blue"}};
        int rand_num_wires = 4 + rand() % 3;    // rand_num_wires = 4,5,6
        string uncutted[6];
        srand(time(0));
        for (int i = 0; i < rand_num_wires; i++) {
            int color = 1 + rand() % 5;
            cout << i + 1 << " " << wire[color] << "  ";
            uncutted[i] = wire[color];
        }
        int correct_num = check_wires(uncutted, rand_num_wires);
        cout << "\n";
        cout << "Choose the NUMBER of wire you want to cut." << endl;
        cout << "Number: ";
        int num = 100;
        cin >> num;
        while (chrono::steady_clock::now() < end_time && num != correct_num) {
            //cout << "Oops!! ERROR!! TIME DEDUCT" << endl;
            // deduct tim
            cout << "Wrong 5 seconds deducted" << endl;
            end_time -= chrono::seconds(5);
            auto remaining_time = chrono::duration_cast<chrono::seconds>(end_time - chrono::steady_clock::now());
            cout << "Time remaining: " << remaining_time.count() << " seconds" << endl;
            cout<<endl;
            cout << "Try again.\nNumber: ";
            cin >> num;

        }
        if (chrono::steady_clock::now() < end_time) {
            cout << "Good job!" << endl;
            auto remaining_time = chrono::duration_cast<chrono::seconds>(end_time - chrono::steady_clock::now());
            cout << "Time remaining: " << remaining_time.count() << " seconds" << endl;
            cout << endl;
            return 1;
        }

    }
    return 0;
}
