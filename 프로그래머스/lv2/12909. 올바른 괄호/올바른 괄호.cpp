#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<int> checks;
    for (auto c : s)
    {
        if (c == '(')
            checks.push(0);
        else
        {
            if (checks.empty())
            {
                return false;
            }

            checks.pop();
        }
    }

    return checks.empty();
}