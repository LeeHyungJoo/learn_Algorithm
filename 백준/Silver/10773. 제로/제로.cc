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

stack<int> costs;
int sum;
int K;

int main()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int c;
		cin >> c;

		if (c == 0)
			costs.pop();
		else
			costs.push(c);
	}

	while (!costs.empty())
	{
		sum += costs.top();
		costs.pop();
	}

	cout << sum;
	return 0;
}