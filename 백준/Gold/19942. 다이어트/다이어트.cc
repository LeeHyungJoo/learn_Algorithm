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
#include <list>

using namespace std;

int answer = numeric_limits<int>::max();
int N;
int values[15];
int m_ingredients[4];

int main()
{
	cin >> N;
	for (int i = 0; i < 4; i++)
		cin >> m_ingredients[i];

	vector<int[4]> m_list(N);
	for (int n = 0; n < N; n++)
	{
		for (int i = 0; i < 4; i++)
			cin >> m_list[n][i];

		cin >> values[n];
	}

	map<string, vector<int>> answer_idx;
	for (int b = 0; b < (1 << N); b++)
	{
		int sum = 0;
		vector<int> ingredients(4, 0);
		for (int n = 0; n < N; n++)
		{
			if (b & (1 << n))
			{
				for (int i = 0; i < 4; i++)
				{
					ingredients[i] += m_list[n][i];
				}
				sum += values[n];
			}
		}

		bool check = true;
		for (int i = 0; i < 4; i++)
		{
			if (m_ingredients[i] > ingredients[i])
			{
				check = false;
				break;
			}
		}

		if (check)
		{
			if (sum < answer)
				answer_idx.clear();

			if (sum <= answer)
			{
				answer = sum;

				string cmp;
				for (int n = 0; n < N; n++)
				{
					if (b & (1 << n))
					{
						cmp.append(to_string(n));
					}
				}

				for (int n = 0; n < N; n++)
				{
					if (b & (1 << n))
					{
						answer_idx[cmp].push_back(n);
					}
				}
			}
		}
	}

	if (answer_idx.empty())
	{
		cout << -1 << endl;
	}
	else
	{
		cout << answer << endl;
		for (int i = 0; i < answer_idx.begin()->second.size(); i++)
		{
			cout << answer_idx.begin()->second[i] + 1 << ' ';
		}
	}



	return 0;
}