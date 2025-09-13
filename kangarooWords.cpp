#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstddef>

using namespace std;

// hardcore in easy puzzle, easy idea but code hard(from process char in string, string in line, multiline)

vector<string> splitMultiDelim(const string &line, const string &delims)
{
    // return vector of string but split delims
    vector<string> result;
    // token to stack chars into word
    string token;

    // scan the string char by char and compare to delims
    for (char c : line)
    {
        // if one char is one of delims (","+" ")
        if (delims.find(c) != string::npos)
        {
            // token has word, input inside vector result -> reset token to new word
            if (!token.empty())
            {
                result.push_back(token);
                token.clear();
            }
        }
        else
        {
            // char into token
            token += c;
        }
    }

    // make sure all char in the end of result
    if (!token.empty())
        result.push_back(token);

    return result;
}

bool areWePair(const string &biggerWord, const string &smallerWord)
{
    // cout << biggerWord << "@" << smallerWord << endl;
    int count = 0, posInBiggerWord = 0;
    for (char cSmall : smallerWord)
    {

        for (; posInBiggerWord < biggerWord.size(); posInBiggerWord++)
        {
            if (cSmall == biggerWord[posInBiggerWord])
            {
                // cout << cSmall << "-" << biggerWord << endl;
                posInBiggerWord++;
                count++;
                break;
            }
        }
    }
    // if (count == smallerWord.size())
    //     cout << biggerWord << " " << smallerWord << ": " << count << endl;
    return count == smallerWord.size() ? true : false;
}

int main()
{
    // input
    int n;
    cin >> n;
    cin.ignore();
    vector<string> lines;
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        lines.push_back(line);
    }
    vector<vector<string>> result;
    vector<string> words;
    bool flagIfLineHavePair = 0;
    // scan kangaroo word: joey word per line
    for (int i = 0; i < n; i++)
    {
        words.clear();
        // split , + space, line into vector line
        vector<string> line = splitMultiDelim(lines[i], ", ");

        // sort size -> alphabet
        sort(line.begin(), line.end(), [](const string &a, const string &b)
             {
                 if (a.size() == b.size())
                     return a < b;
                 return a.size() > b.size(); // longer go first
             });

        // scan

        for (int pos = 0; pos < line.size(); pos++)
        {
            vector<int> pairPosition;
            for (int nextPosToScan = pos + 1; nextPosToScan < line.size(); nextPosToScan++)
            {
                // check the small size word (nextPos) char (position must be bigger than older char)
                if (areWePair(line[pos], line[nextPosToScan]) == 1)
                {
                    pairPosition.push_back(nextPosToScan);
                    flagIfLineHavePair = true;
                }
            }
            if (pairPosition.size() > 0)
            {

                words.push_back(line[pos]);
                // cout << line[pos] << ":";
                bool flagFirstJoeyWord = true;
                for (int &i : pairPosition)
                    words.push_back(line[i]);
                // if (flagFirstJoeyWord == true)
                // {

                //     cout << " " << line[i];
                //     flagFirstJoeyWord = false;
                // }
                // else
                //     cout << ", " << line[i];
                // cout << endl;
            }
        }
        if (words.empty() == false)
            result.push_back(words);
        // // // test line
        // for (int j = 0; j < line.size(); j++)
        //     cout << line[j] << " ";
    }

    sort(result.begin(), result.end(), [](const vector<string> &a, const vector<string> &b)
         {
    if (a[0]==b[0]) return a.size() > b.size(); 
    return a[0] < b[0]; });

    for (auto &entry : result)
    {
        string kangaroo = entry[0];
        vector<string> joeys(entry.begin() + 1, entry.end());

        sort(joeys.begin(), joeys.end());

        cout << kangaroo << ": ";
        for (size_t i = 0; i < joeys.size(); i++)
        {
            if (i > 0)
                cout << ", ";
            cout << joeys[i];
        }
        cout << endl;

        // if (flagIfLineHavePair == false)
        //     cout << "NONE" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     vector<int> count_letters;
        //     for (int j = 0; j < lines[i][])
        // }

        // output lines to test
        //  for (int i = 0; i < n; i++) {
        //      cout << lines[i] << endl;
        //  }
    }
}