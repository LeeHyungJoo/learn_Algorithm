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

int K;
int serials[1024] = {};
vector<int> trees[10];


void InOrderedSearch(int start, int end, int level)
{
	if (start == end)
	{
		trees[level].push_back(serials[start]);
		return;
	}

	int center_idx = (start + end) >> 1;
	trees[level].push_back(serials[center_idx]);

	InOrderedSearch(start, center_idx - 1, level + 1);
	InOrderedSearch(center_idx + 1, end, level + 1);
}

int main()
{
	cin >> K;

	int end = (int)pow(2, K) - 1;
	for (int i = 0; i < end; i++)
	{
		cin >> serials[i];
	}

	InOrderedSearch(0, end - 1, 0);

	for (auto t : trees)
	{
		for (auto item : t) 
		{
			cout << item << ' ';
		}
		cout << '\n';
	}

	return 0;
}