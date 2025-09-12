#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void printWhiteorBlack(int &countPixel, int &isWhite)
{
     if (isWhite % 2 == 0)
                    cout << "*";
                else
                    cout << " ";
                countPixel--;
}

int main()
{
    // input
    int width, height;
    cin >> width;
    cin.ignore();
    cin >> height;
    cin.ignore();
    string pixelThenSwapColor;
    getline(cin, pixelThenSwapColor);

    // extract to int
    vector<int> whiteOrBlack;
    int token;
    stringstream ss(pixelThenSwapColor);
    while (ss >> token)
        whiteOrBlack.push_back(token);

    int isWhite = 0;                        // odd is white, even is black
    int countPixel = whiteOrBlack[isWhite]; // > 0 => % 2 == 0 (*), %2!= 0 (space)

    // top to bottom
    for (int i = 0; i < height; i++)
    {
        // left to right (line by line)
        cout << "|";
        for (int j = 0; j < width; j++)
        {
            //cout << j;
            if (countPixel > 0)
            {
               printWhiteorBlack(countPixel, isWhite);
            }
            else
            {
                isWhite++;
                // cout << isWhite;
                countPixel = whiteOrBlack[isWhite];
                printWhiteorBlack(countPixel,isWhite);
            }
        }
        cout << "|" << endl;
        ///cout << width << endl;
    }

    // test the whiteOrBlack
    // for (int i=0;i<whiteOrBlack.size();i++)
    // {
    //     cout << whiteOrBlack[i];
    // }
}