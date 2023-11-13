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

int k;
char marks[9] = {};
int selected[10] = {};
bool bFind = false;

vector<int> answers;

void DFS_upper(int idx, int val)
{
	if (bFind)
	{
		return;
	}

	selected[val] = 1;
	answers.push_back(val);

	if (answers.size() == k + 1)
	{
		for (auto c : answers)
		{
			cout << c;
		}
		bFind = true;
		return;
	}

	for (int i = 9; i >= 0; i--)
	{
		if (selected[i] > 0)
		{
			continue;
		}

		if (marks[idx] == '<')
		{
			if (val > i)
			{
				continue;
			}
		}
		else
		{
			if (val < i)
			{
				continue;
			}
		}

		DFS_upper(idx + 1, i);
	}

	selected[val] = 0;
	answers.pop_back();
}

void DFS_lower(int idx, int val)
{
	if (bFind)
	{
		return;
	}

	selected[val] = 1;
	answers.push_back(val);

	if (answers.size() == k + 1)
	{
		for (auto c : answers)
		{
			cout << c;
		}
		bFind = true;
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (selected[i] > 0)
		{
			continue;
		}

		if (marks[idx] == '<')
		{
			if (val > i)
			{
				continue;
			}
		}
		else
		{
			if (val < i)
			{
				continue;
			}
		}

		DFS_lower(idx + 1, i);
	}

	selected[val] = 0;
	answers.pop_back();
}

int main()
{
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> marks[i];
	}

	for (int start = 9; start >= 0; start--)
	{
		DFS_upper(0, start);
		memset(selected, 0, sizeof(selected));
		answers.clear();
		if (bFind)
		{
			break;
		}
	}

	cout << endl;
	bFind = false;


	for (int start = 0; start <=  9; start++)
	{
		DFS_lower(0, start);
		memset(selected, 0, sizeof(selected));
		answers.clear();
		if (bFind)
		{
			break;
		}
	}

	return 0;
}