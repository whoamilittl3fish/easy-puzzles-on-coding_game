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
    int c;
    cin >> c;
    cin.ignore();
    int p;
    cin >> p;
    cin.ignore();

    vector<string> vector_items;
    for (int iteration = 0; iteration < c; iteration++)
    {
        string item;
        getline(cin, item);
        vector_items.push_back(item);
    }
    vector<string> vector_orders;
    for (int iteration = 0; iteration < p; iteration++)
    {
        string order;
        getline(cin, order);
        vector_orders.push_back(order);
    }

    for (int iteration = 0; iteration < vector_orders.size(); iteration++)
    {
        bool if_we_have_item_fit_your_order = 0;
        vector<string> per_order;
        stringstream ss(vector_orders[iteration]);
        string token;
        while (getline(ss, token, ' '))
        {
            per_order.push_back(token);
        }

        int min_price = INT_MAX, position_of_min_price = -1;
        for (int j = 0; j < vector_items.size(); j++)
        {

            stringstream ss2(vector_items[j]);
            string name, size;
            int price;
            ss2 >> name >> size >> price;
            if ((per_order[0] == name && per_order[1] == size) && (vector_orders[iteration][0] != 'X'))
            {
                if (price < min_price)
                {
                    min_price = price;
                    position_of_min_price = j;
                }
            }
        }
        if (position_of_min_price == -1)
            cout << "NONE" << endl;
        else
        {
            vector_items[position_of_min_price][0] = 'X';
            cout << min_price << endl;
        }
    }

    // for (int iteration =0; iteration < vector_items.size();iteration++)
    // {
    //     cout << vector_items[iteration] << endl;
    // }
}