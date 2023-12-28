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

int N, K;
int coins[10];

int main()
{
	cin >> N >> K;
	for (int i = N; i > 0; i--)
		cin >> coins[i - 1];

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (coins[i] > K)
			continue;

		int per = K / coins[i];
		K -= (per * coins[i]);
		cnt += per;
	}

	cout << cnt << endl;
	return 0;
}