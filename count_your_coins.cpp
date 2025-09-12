#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
using namespace std;

// Struct that have value, count of coin
struct Coin
{
    int value;
    int count;
};

// compare 2 coins by value
bool Compare_Coin_By_Value(const Coin &a, const Coin &b)
{
    return a.value < b.value;
}

int main()
{
    // sum of value to reach
    int value_to_reach;
    cin >> value_to_reach;
    cin.ignore();

    // how many type of coin in pocket
    int count_of_coin;
    cin >> count_of_coin;
    cin.ignore();

    // vector -> input pair (number, value) to vector coins
    vector<Coin> coins(count_of_coin);

    // input count, value of coin one by one
    for (int i = 0; i < count_of_coin; i++)
    {
        cin >> coins[i].count;
    }
    for (int i = 0; i < count_of_coin; i++)
    {
        cin >> coins[i].value;
    }

    sort(coins.begin(), coins.end(), Compare_Coin_By_Value);

    // count the coin need to grab
    int sum_of_value = 0; // sum of value until end of grab
    int sum_of_coin = 0;  // sum of coin until grab end
    for (int i = 0; i < count_of_coin; i++)
    {
        for (int j = 0; j < coins[i].count; j++)
        {
            sum_of_coin += 1;
            sum_of_value += coins[i].value;
            if (sum_of_value >= value_to_reach)
                break;
        }
        if (sum_of_value >= value_to_reach)
            break;
    }

    // check the sum of value
    //cout << sum_of_value << endl;

    if (sum_of_value >= value_to_reach)

        cout << sum_of_coin << endl;
    else
        cout << -1 << endl;

    // test output coin
    // for (auto &coin : coins)
    // {
    //     cout << "(" << coin.count << "," << coin.value << ")";
    // }
}
