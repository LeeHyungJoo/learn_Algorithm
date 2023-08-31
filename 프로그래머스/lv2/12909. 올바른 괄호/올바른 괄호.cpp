#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	int stack = 0;
	for (const auto& ch : s)
	{
		stack += ch == '(' ? +1 : -1;
		if (stack < 0)
			return false;
	}

    return stack == 0;
}