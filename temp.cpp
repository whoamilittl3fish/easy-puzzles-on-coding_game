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
    int n;
    cin >> n;
    cin.ignore();
    vector<int> ints;
    int min = 1000000000;
    bool pos = false;
    if (n == 0)
        cout << "0";
    else
    {
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            if (abs(num) < min)
            {
                if (num > 0)
                    pos = true;
                else
                    pos = false;
                min = num;
            }
            ints.push_back(num);
        }

        pos == true ? cout << min : cout << (-min);
    }
}