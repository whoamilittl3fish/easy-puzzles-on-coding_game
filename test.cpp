#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int integer[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> integer[i][j];
        }
    }
    int att;
    cin >> att;

    int sum=0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (integer[i][j] == att)
            sum++;
        }
    }
    cout << sum-1 << endl;
}