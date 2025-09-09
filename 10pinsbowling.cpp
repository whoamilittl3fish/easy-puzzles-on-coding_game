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

int main()
{
    // calculate score for one frame
    // auto frame_score = [](const string &str) -> int
    // {
    //     int score = 0;
    //     for (int i = 0; i < str.size(); i++)
    //     {
    //         if (str[i] == 'X')
    //             score += 10;
    //         else if (str[i] == '/')
    //             score += (10 - (str[i - 1] - '0'));
    //         else if (str[i] == '-')
    //             score += 0;
    //         else
    //             score += (str[i] - '0');
    //     }
    //     return score;
    // };

    int n, score, previous_score;
    cin >> n;
    cin.ignore();
    vector<string> games;
    for (int i = 0; i < n; i++)
    {
        // One game of 10-pin bowling
        string one_game;
        getline(cin, one_game);
        games.push_back(one_game);
    }

    for (int i = 0; i < n; i++)
    {
        string frame;
        stringstream ss(games[i]);
        vector<string> game;
        while (ss >> frame)
            game.push_back(frame);

        // sum score in one game
        previous_score = 0;
        for (int i = 0; i < 10; i++)
        {
            score = 0;

            // can try to use recursive function
            if (game[i] == "X" && i < 8)
            {
                score += 10;
                // double strike
                if (game[i + 1] == "X")
                {
                    score += 10;
                    // triple strike
                    if (game[i + 2][0] == 'X')
                        score += 10;
                    // or not :D
                    else
                        score += game[i + 2][0] == '-' ? 0 : (game[i + 2][0] - '0');
                }
                // strike then spare
                else if (game[i + 1][1] == '/')
                    score += 10;
                // strike then open frame
                else
                {
                    score += game[i + 1][0] == '-' ? 0 : (game[i + 1][0] - '0');
                    score += game[i + 1][1] == '-' ? 0 : (game[i + 1][1] - '0');
                }
            }
            // strike in next to last frame
            else if (game[i][0] == 'X' && i == 8)
            {
                score += 10;
                if (game[i + 1][0] == 'X')
                {
                    score += 10;
                    if (game[i + 1][1] == 'X')
                        score += 10;
                    else
                        score += game[i + 1][1] == '-' ? 0 : (game[i + 1][1] - '0');
                }
                else if (game[i + 1][1] == '/')
                    score += 10;
                else
                {
                    score += game[i + 1][0] == '-' ? 0 : (game[i + 1][0] - '0');
                    score += game[i + 1][1] == '-' ? 0 : (game[i + 1][1] - '0');
                }
            }
            // spare in next to last frame
            else if (game[i][1] == '/' && i == 8)
            {
                score += 10;
                if (game[i + 1][0] == 'X')
                    score += 10;
                else
                    score += game[i + 1][0] == '-' ? 0 : (game[i + 1][0] - '0');
            }
            // open frame in next to last frame
            else if (i==8)
            {
                score += game[i][0] == '-' ? 0 : (game[i][0] - '0');
                score += game[i][1] == '-' ? 0 : (game[i][1] - '0');
            }
            // last frame
            else if (i == 9)
            {
                if (game[i][0] == 'X')
                {
                    score += 10;
                    if (game[i][1] == 'X')
                    {
                        score += 10;
                        if (game[i][2] == 'X')
                            score += 10;
                        else
                            score += game[i][2] == '-' ? 0 : (game[i][2] - '0');
                    }
                    else if (game[i][2] == '/')
                        score += 10;

                    else
                    {
                        score += game[i][1] == '-' ? 0 : (game[i][1] - '0');
                        score += game[i][2] == '-' ? 0 : (game[i][2] - '0');
                    }
                }
                else if (game[i][1] == '/')
                {
                    score += 10;
                    if (game[i][2] == 'X')
                        score += 10;
                    else
                        score += game[i][2] == '-' ? 0 : (game[i][2] - '0');
                }
                else
                {
                    score += game[i][0] == '-' ? 0 : (game[i][0] - '0');
                    score += game[i][1] == '-' ? 0 : (game[i][1] - '0');
                }
            }
            // spare
            else if (game[i][1] == '/')
            {
                score += 10;
                // next is strike
                if (game[i + 1][0] == 'X')
                    score += 10;
                else
                    score += game[i + 1][0] == '-' ? 0 : (game[i + 1][0] - '0');
            }
            // open frame
            else
            {
                score += game[i][0] == '-' ? 0 : (game[i][0] - '0');
                score += game[i][1] == '-' ? 0 : (game[i][1] - '0');
            }
            // cout << score << " ";
            // cout << endl;
            previous_score += score;
            if (i == 9)
                cout << previous_score;
            else
                cout << previous_score << " ";
        }
        cout << endl;
    }
}
