#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int numbers_of_horse, iteration;
    cin >> numbers_of_horse;
    cin.ignore();
    vector<int> horse_power;
    for (iteration = 0; iteration < numbers_of_horse; iteration++)
    {
        int power;
        cin >> power; cin.ignore();
        horse_power.push_back(power);
    }
    sort(horse_power.begin(), horse_power.end());
    iteration = 0;
    //last case is base to compare 
    int min_diff = horse_power[numbers_of_horse-1] - horse_power[numbers_of_horse-2];
   for (;iteration < numbers_of_horse-2;iteration++)
   {
        int diff = horse_power[iteration + 1] - horse_power[iteration];
        if (diff < min_diff)
            min_diff = diff;
   }
   cout << min_diff << endl;
}