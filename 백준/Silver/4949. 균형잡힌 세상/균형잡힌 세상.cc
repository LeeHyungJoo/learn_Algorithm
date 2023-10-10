#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>
#include <regex>
#include <iostream>

using namespace std;

bool CheckBalance(const string& str)
{
    stack<char> check;
    for (int i = 0; i < str.size();i++)
    {
        auto c = str[i];
        if (c == '(' || c == '[')
        {
            check.push(c);
        }
        else if (c == ')')
        {
            if (check.empty())
                return false;

            if (check.top() == '(')
                check.pop();
            else
                check.push(c);

        } 
        else if (c == ']')
        {
            if (check.empty())
                return false;

            if (check.top() == '[')
                check.pop();
            else
                check.push(c);
        }
    }

    return check.empty();
}



int  main()
{
    while (true) 
    {
        string s;
        getline(cin, s);
        if (s == ".") 
            break;

        if (CheckBalance(s))
            cout << "yes\n";
        else
            cout << "no\n";
    }

	return 0;
}