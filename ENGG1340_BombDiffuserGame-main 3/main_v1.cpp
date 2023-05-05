

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));

    char two_d_list[3][5] = {
            {'a', 'b', 'c', 'd', 'e'},
            {'f', 'i', 'j', 'k', 'l'},
            {'m', 'n', 'o', 'p', 'q'}
    };

    int random_row = rand() % 3;
    cout << random_row << endl;
    char list1[5]; // declare list1 as a one-dimensional character array
    int random_indices[4];
    for (int i = 0; i < 5; i++) {
        list1[i] = two_d_list[random_row][i];
        cout<<list1[i];
    }
    cout << endl;

    for (int i = 0; i < 4; i++) {
        int index;
        do {
            index = rand() % 5;
        } while (index == random_indices[0] || index == random_indices[1] || index == random_indices[2] || index == random_indices[3]);
        random_indices[i] = index;
    }
    for (int i = 0; i < 4; i++) {
        cout << list1[random_indices[i]] << " ";
    }
    cout << endl;















