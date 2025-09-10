#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int calculate_score(string cards)
{
    string one_card;
    int score = 0;
    stringstream ss_cards(cards);

    // scan blackjack first
    int count_cards = 0;
    int has_A = 0;
    while (ss_cards >> one_card)
    {
        if (one_card[0] >= '2' && one_card[0] <= '9')
        {
            // flag that not blackjack
            count_cards -= 1000;
            continue;
        }
        if (one_card[0] == 'A')
        {
            count_cards++;
            has_A = 1;
            continue;
        }
        else if (one_card[0] == 'J' || one_card[0] == 'Q' || one_card[0] == 'K' ||
                 one_card == "10")
        {
            count_cards++;
            continue;
        }
    }
    if (count_cards == 2 && has_A == 1)
        return 999;
    else
    {
        ss_cards.clear();
        ss_cards.seekg(0);
        score = 0;
        // scan not A
        while (ss_cards >> one_card)
        {
            if (one_card[0] >= '2' && one_card[0] <= '9')
                score += one_card[0] - '0';
            else if (one_card[0] == 'J' || one_card[0] == 'Q' || one_card[0] == 'K' ||
                     one_card == "10")
                score += 10;
        }
        ss_cards.clear();
        ss_cards.seekg(0);
        // scan A
        while (ss_cards >> one_card)
        {
            if (one_card[0] == 'A')
            {
                if (score + 11 <= 21)
                    score += 11;
                else
                    score += 1;
            }
        }
        return score;
    }
}

int main()
{
    string bank_cards;
    getline(cin, bank_cards);
    string player_cards;
    getline(cin, player_cards);

    int bank_score = calculate_score(bank_cards);
    int player_score = calculate_score(player_cards);
    if (player_score == bank_score)
    {
        if (player_score > 21 and bank_score > 21)
            cout << "Bank" << endl;
        else
            cout << "Draw" << endl;
    }
    else if (bank_score == 999 && player_score != 999)
        cout << "Bank" << endl;
    else if (player_score == 999 && bank_score != 999)
        cout << "Blackjack!" << endl;
    else if (player_score == 999 && bank_score == 999)
        cout << "Draw" << endl;
    else if (player_score > 21 && bank_score > 21)
        cout << "Bank" << endl;
    else if (player_score > 21 && bank_score <= 21)
        cout << "Bank" << endl;
    else if (bank_score > 21 && player_score <= 21)
        cout << "Player" << endl;
    else
    {
        if (player_score > bank_score)
            cout << "Player" << endl;
        else if (bank_score > player_score)
            cout << "Bank" << endl;
        else
            cout << "Draw" << endl;
    }
    // cout << "Bank: " << bank_score << endl;
    // cout << "Player: " << player_score << endl;
}