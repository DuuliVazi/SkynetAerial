#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//Creates array class called 'arr'.
void show(int arr[], int size)
{

    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
}

int main()
{
    //Seeds random number generator with current time.
    srand(static_cast<unsigned int>(time(0)));
    //Generates random number generator where enemy is located. And it could be anywhere between 1-64.
    int killzone = rand() % 64 + 1;
    //Passes 64 values through array.
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64};
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    int tries = 0;
    //Tells Skynet software the highest value in grid is 64 and lowest value is 1.
    int searchGridHighNumber = 64;
    int searchGridLowNumber = 1;
    //Software selects target location while flying.
    int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

    //Displays 8x8 grid with all 64 values to Skynet. 
    cout << "\n******** CONFIGURING 8X8 ENEMY DETECTION GRID ********\n";
    sort(arr, arr + arrsize);
    show(arr, arrsize);

    //Tells Skynet where enemy is located based on grid.
    cout << "\n\nTAKE A LOOK AT THIS 8X8 GRID, THE ENEMY IS HERE: " << killzone << "\n\n";
    do
    {
        //Counts number of times Skynet has to retrieve new value.
        ++tries;

        //Condition regarding predicted target area being greater than actual enemy location.
        if (targetLocationPrediction > killzone)
        {
            //Outputs prediction with actual enemy location. Then asks Skynet for another prediction.
            cout << "THE TARGET LOCATION, " << targetLocationPrediction << "\nIS HIGHER THAN ENEMY LOCATION, " << killzone << endl;
            "\\n";
            cout << "SKYNET HK-AERIAL NEEDS ANOTHER RETRIEVAL # " << tries << endl;
            //Gets rid of values too high of actual location, along with incorrect guess.
            searchGridHighNumber = targetLocationPrediction - 1;
            targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
        }
        //Condition regarding predicted target area being lower than actual enemy location.
        else if (targetLocationPrediction < killzone)
        {
            //Outputs prediction with actual enemy location. Then asks Skynet for another prediction.
            cout << "THE TARGET LOCATION, " << targetLocationPrediction << "\nIS LOWER THAN ENEMY LOCATION, " << killzone << endl;
            cout << "SKYNET HK-AERIAL NEEDS ANOTHER RETRIEVAL # " << tries << endl;
            //Gets rid of values too low of actual location, along with incorrect guess.
            searchGridLowNumber = targetLocationPrediction + 1;
            targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
        }
        //Condition saying if predicted target area equals actual enemy location, then perform all these actions.
        if (targetLocationPrediction == killzone)
        {
            cout << "\nENEMY SPOTTED\n";
             cout << "\n**SKYNET SEARCHING FOR MORE POTENTIAL ENEMIES IN AREA**\n";
            cout << "\n----RECONFIGURING SKYNET HK-AERIAL FIRE SYSTEMS----\n";
            cout << "\nDRONE LOCKED ON ENEMY...COMMENCE FIRE!!\n";
            cout << "\nENEMY ELIMINATED\n";
        }
      //Allows Skynet to keep looping until actual enemy location is spotted.  
    } while (targetLocationPrediction != killzone);

    return 0;
}
