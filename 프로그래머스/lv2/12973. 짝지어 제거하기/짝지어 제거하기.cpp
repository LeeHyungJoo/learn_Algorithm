#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
	stack<char> checks;
	for (auto c : s)
	{
		if (!checks.empty() && checks.top() == c)
			checks.pop();
		else
			checks.push(c);
	}

    return checks.size() == 0 ? 1 : 0;
}