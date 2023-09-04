#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>

using namespace std;


int main()
{
	int count = 0;
	cin >> count;

	vector<string> words(count);
	for (int i = 0; i < words.size(); i++)
		cin >> words[i];

	int answer = 0;
	for (auto& word : words)
	{
		stack<char> checks;
		for (auto c : word)
		{
			if (checks.empty())
			{
				checks.push(c);
				continue;
			}

			if (checks.top() == c)
				checks.pop();
			else
				checks.push(c);
		}

		if (checks.empty())answer++;
	}

	cout << answer;

	return 0;
}