#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    // input
    string order;
    getline(cin, order);
    string strSide, strOpposite;
    getline(cin, strSide);

    // set opposite
    if (strSide[0] == 'L')
        strOpposite = 'R';
    else if (strSide[0] == 'R')
        strOpposite = 'L';
    else if (strSide[0] == 'U')
        strOpposite = 'D';
    else if (strSide[0] == 'D')
        strOpposite = 'U';

    // test side
    // cout << strSide << "," << strOpposite << endl;

    // the idea is count the side and opposite, if folding at one side (either side or opposite side)
    // it will sum all to the other side and reset side to 1.
    // count side + opposite
    int countSide = 1, countOpposite = 1;
    for (int i = 0; i < order.size(); i++)
    {
        // cout << i << ":";
        if (order[i] == strSide[0])
        {
            countOpposite += countSide;
            countSide = 1;
        }
        else if (order[i] != strOpposite[0])
        {
            countOpposite *= 2;
        }
        if (order[i] == strOpposite[0])
        {
            countSide += countOpposite;
            countOpposite = 1;
        }
        else if (order[i] != strSide[0])
        {
            countSide *= 2;
        }
        // cout << countSide << "," << countOpposite << endl;
    }

    cout << countSide << endl;

    // //test output input
    // for (int i=0;i<order.size();i++)
    // {
    //     cout << order[i] << endl;
    // }
    // cout << count_folds << endl;
}