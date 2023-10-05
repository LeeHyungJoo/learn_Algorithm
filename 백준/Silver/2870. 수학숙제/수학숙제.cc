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


bool CustomCompare(const string& lhs, const string& rhs)
{
	if (lhs.size() == rhs.size())
		return lhs < rhs;
	else
		return lhs.size() < rhs.size();
}


int  main()
{
	int cnt = 0;
	cin >> cnt;

	vector<string> checks;
	for (int i = 0; i < cnt; i++)
	{
		string str;
		cin >> str;

		string buf;
		for (auto c : str)
		{
			if (isdigit(c))
			{
				buf.push_back(c);
			}
			else if(!buf.empty())
			{
				checks.push_back(buf);
				buf.clear();
			}
		}

		if (!buf.empty())
		{
			checks.push_back(buf);
		}
	}

	for (auto& c : checks)
	{
		while (c.size() != 1)
		{
			auto zc = c.find('0');
			if (zc != 0) break;
			c.erase(zc,1);
		}
	}

	sort(checks.begin(), checks.end(), CustomCompare);
	for (auto c : checks)
	{
		cout << c << endl;
	}

	return 0;
}