#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// x: horizontal, y: vertical
int burn_around_cell_fire(int x, int y, vector<string> &lines)
{
    // check corner -> burn
    for (int i = x; (x + i) < 6, i < 3; i++)
    {
        for (int j = y; (y + j) < 6, j < 3; j++)
        {
            
        }
    }
}

int main()
{
    // input map
    vector<string> lines;
    for (int i = 0; i < 6; i++)
    {
        string line;
        getline(cin, line);
        lines.push_back(line);
    }

    // fires to check is that fake new :D
    int fires = 0;
    int cell_not_fire = 0;
    // check fire by cell
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (lines[i][j] == '*')
            {
                fires++;
            }
            else
                cell_not_fire++;
        }
    }

    // output
    if (fires == 0)
        cout << "RELAX" << endl;
    else if (fires + cell_not_fire == 36)
    {
        cout << "JUST RUN" << endl;
    }
    else
    {
    }

    // output map
    for (int i = 0; i < 6; i++)
    {
        cout << lines[i] << endl;
    }
}