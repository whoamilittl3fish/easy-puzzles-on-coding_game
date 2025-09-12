#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string scan_4_adjacecy_direction(vector<string> &grid, int width, int height, int position_height, int position_width)
{
    //cout << "flag 3" << endl;
    int sum_of_adjacency_passeble = 0;
    // under
    if (position_height < height)
    {
        //cout << position_height << " " << height << endl;
        if (grid[position_height + 1][position_width] != '#')
            sum_of_adjacency_passeble++;
    }
    // above
    //cout << "check_above_1";
    if (position_height > 0)
    {
        //cout << "check_above";
        if (grid[position_height - 1][position_width] != '#')
            sum_of_adjacency_passeble++;
    }
    // left
    if (position_width > 0)
    {
        //cout << "check_left";
        if (grid[position_height][position_width-1]!= '#')
            sum_of_adjacency_passeble++;
    }
    // right
     if (position_width < width)
    {
        //cout << "check_right";
        if (grid[position_height][position_width+1]!= '#')
            sum_of_adjacency_passeble++;
    }
    //cout << "flag_4" << endl;
    string result = to_string(sum_of_adjacency_passeble);
    return result;
}

int main()
{
    int width;
    int height;
    cin >> width >> height;
    cin.ignore();

    // vector grid input with n string lines
    vector<string> grid(height);
    for (int i = 0; i < height; i++)
    {
        cin >> grid[i];
    }

    // process the map
    for (int i = 0; i < height; i++)
    {
        //cout << "flag_1" << endl;
        for (int j = 0; j < width; j++)
        {
            if (grid[i][j] != '#')
            {
                //cout << "flag_2" << endl;
                grid[i][j] = scan_4_adjacecy_direction(grid, width-1, height-1, i, j)[0];
            }
        }
    }
    // cout << endl;
    // print the map
    for (int i = 0; i < height; i++)
    {
            cout << grid[i] << endl;
    }
}