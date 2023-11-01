
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <stack>
#include <numeric>
#include <unordered_map>

using namespace std;


vector<char> exprs;
vector<bool> expr_checks;

vector<int> dp;

vector<int> numbers;
int max_value = -999999999;

int Calculate(char type, int lhs, int rhs)
{
	switch (type)
	{
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	case '*':
		return lhs * rhs;
	}
	return 0;
}


void BruteForce(int expr_idx, bool include)
{
	if (expr_idx == exprs.size())
	{
		int val;
		int idx = 0;
		if (expr_checks[0])
		{
			val = dp[0];
			idx = 1;
		}
		else
		{
			val = numbers[0];
		}

		while (idx < exprs.size())
		{
			if (idx + 1 < exprs.size() && expr_checks[idx + 1])
			{
				val = Calculate(exprs[idx], val, dp[idx + 1]);
				idx += 2;
			}
			else
			{
				val = Calculate(exprs[idx], val, numbers[idx + 1]);
				idx += 1;
			}
		}

		if (max_value < val)
			max_value = val;

		return;
	}

	expr_checks[expr_idx] = include;

	if (include)
	{
		//다음은 false 처리
		BruteForce(expr_idx + 1, false);
	}
	else
	{
		//true나 false  할 수 있음. 
		BruteForce(expr_idx + 1, true);
		BruteForce(expr_idx + 1, false);
	}

	expr_checks[expr_idx] = !include;
}


int main()
{
	int c;
	cin >> c;

	string str;
	cin >> str;

	if (c == 1)
	{
		cout << atoi(&str[0]);
		return 0;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (i & 1)
		{
			exprs.push_back(str[i]);
		}
		else
		{
			numbers.push_back(atoi(&str[i]));
		}
	}

	expr_checks.resize(exprs.size(), false);
	dp.resize(exprs.size(), 0);

	for (int i = 0; i < dp.size(); i++)
	{
		dp[i] = Calculate(exprs[i], numbers[i], numbers[i + 1]);
	}

	BruteForce(0, true);
	BruteForce(0, false);

	cout << max_value;
	return 0;
}

