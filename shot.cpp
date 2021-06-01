#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//Have to stash contents of array before performing binary_search algo.
void show(int arr[], int size) {

    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}

int main() {

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64 };
    int enemy[] = { 36, 37, 38 };
    int enemysize = sizeof(enemy) / sizeof(enemy[0]);
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    cout << "\nTHIS 8X8 GRID IS VERY LARGE, BUT THAT DOESN'T HINDER ENEMY DETECTION\n";
    show(arr, arrsize);

    cout << "\n\n\n--------SKYNET HK-AERIAL DRONE DETECTING KILLZONE--------\n\n\n";
    cout << "\nSKYNET HK-AERIAL NARROWING KILLZONE\n\n";
    sort(arr, arr + arrsize);
    cout << "\nTHERE ARE THREE ENEMIES POSITIONED AT 36, 37, 38\n\n";
    show(enemy, enemysize);
    cout << "\n\nTAKE YOUR TIME, BREATH, AND FIRE\n\n";
    if (binary_search(arr, arr + 64, 2))
        cout << "\nENEMY SPOTTED!";
    else 
        cout << "\nTHAT'S NOT OUR GUY";

    cout << "\n\nNow, say we want to search for 10";
    if (binary_search(arr, arr + 10, 10))
        cout << "\nENEMY SPOTTED!";
    else   
        cout << "\nTHAT'S NOT OUR GUY";
    return 0;
}
    



