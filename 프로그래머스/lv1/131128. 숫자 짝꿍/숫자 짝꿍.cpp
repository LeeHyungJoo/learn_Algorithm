#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer;

    map<char, int/*count*/, greater<char>> x_value_map;
    map<char, int/*count*/, greater<char>> y_value_map;
    map<char, int/*count*/, greater<char>> value_map;

    for (auto ch : X)
        x_value_map[ch]++;

    for (auto ch : Y)
        y_value_map[ch]++;

    bool emptyCheck = false;
    char last_c = ' ';
    for (char c = '0'; c <= '9'; c++)
    {
        auto x_itr = x_value_map.find(c);
        auto y_itr = y_value_map.find(c);

        if (x_itr != x_value_map.end() 
            && y_itr != y_value_map.end() )
        {
            if ((*x_itr).second > (*y_itr).second)
                value_map[c] = (*y_itr).second;
            else
                value_map[c] = (*x_itr).second;
            emptyCheck = true;
            last_c = c;
        }
        else
        {
            value_map[c] = 0;
        }
    }

    if (emptyCheck == false)
        return "-1";

    if (last_c == '0')
        return "0";

    for (auto x : value_map)
    {
        if (x.second == 0)
            continue;
       
        answer.append(x.second, toascii(x.first));
    }


    return answer;
}