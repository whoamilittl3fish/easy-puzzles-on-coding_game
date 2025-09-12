#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

bool is_string_of_cards(string string_to_check)
{
    string cards[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    int flag;
    for (int i = 0; i <= string_to_check.size() - 1; i++)
    {
        flag = 0;
        for (int j = 0; j <= 12; j++)
        {
            if (string_to_check[i] == cards[j][0])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return false;
    }
    return true;
}

float card_remaining_per_value(vector<string> cards_seen, int bust_threshold)
{
    int need = (bust_threshold-1)*4, all = 52;
    string token;
    for (int i = 0; i < cards_seen.size(); i++)
    {
        token = cards_seen[i];
        for (int j = 0; j < token.size(); j++)
        {
            if (token[j] == 'A')
                {
                    need -= 1;
                    //cout << "need + 1 for A" << endl;
                }
            else if (bust_threshold > 2 && token[j] == '2')
                {
                    need -= 1;
                    //cout << "need + 1 for 2" << endl;
                }
            else if (bust_threshold > 3 && token[j] == '3')
                {
                    need -= 1;
                    //cout << "need + 1 for 3" << endl;
                }
            else if (bust_threshold > 4 && token[j] == '4')
                {
                    need -= 1;
                    //cout << "need + 1 for 4" << endl;
                }
            else if (bust_threshold > 5 && token[j] == '5')
                {
                    need -= 1;
                    //cout << "need + 1 for 5" << endl;
                }
            else if (bust_threshold > 6 && token[j] == '6')
                 {
                    need -= 1;
                    //cout << "need + 1 for 6" << endl;
                }
            else if (bust_threshold > 7 && token[j] == '7')
                 {
                    need -= 1;
                    //cout << "need + 1 for 7" << endl;
                }
            else if (bust_threshold > 8 && token[j] == '8')
                 {
                    need -= 1;
                    //cout << "need + 1 for 8" << endl;
                }
            else if (bust_threshold > 9 && token[j] == '9')
                 {
                    need -= 1;
                    //cout << "need + 1 for 9" << endl;
                }
            else if (bust_threshold > 10 && (token[j] == 'T' || token[j] == 'J' || token[j] == 'Q' || token[j] == 'K'))
                 {
                    need -= 1;
                    //cout << "need + 1 for 10" << endl;
                }
            all -=1;
        }
    }
    int result = (int)round((float)need / all * 100);
    return result;
}

int main()
{
    string stream_of_consciousness;
    getline(cin, stream_of_consciousness);
    int bust_threshold;
    cin >> bust_threshold;
    cin.ignore();

    vector<string> cards_seen;
    stringstream ss(stream_of_consciousness);
    string token;
    while (getline(ss, token, '.'))
    {
        if (is_string_of_cards(token))
        {
            cards_seen.push_back(token);
        }
    }
    cout << card_remaining_per_value(cards_seen, bust_threshold) << "%" << endl;
}
