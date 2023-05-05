#ifndef NUMBER_GAME_H
#define NUMBER_GAME_H
#include <chrono>
using namespace std;

int stage1(int array[], std::chrono::steady_clock::time_point& end_time);   //function for stage 1 which inputs an array
int stage2(int array[],int key1, std::chrono::steady_clock::time_point& end_time);  //function for stage 1 which inputs an array and the first key
int stage3(int array[],int key1,int key2, std::chrono::steady_clock::time_point& end_time);   //function for stage 1 which inputs an array, the first and the second key
int stage4(int array[],int key1,int key2, int key3, std::chrono::steady_clock::time_point& end_time);   //function for stage 1 which inputs an array, the first, the second and the third key
int stage5(int array[],int key1, int key2, int key3, int key4, std::chrono::steady_clock::time_point& end_time);  //function for stage 1 which inputs an array, the first, the second, the third and the fourth key
void printarray(int arr[]);
int number_game(std::chrono::steady_clock::time_point& end_time);

#endif

