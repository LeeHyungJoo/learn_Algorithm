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
int bits[20];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int sum = 0;

		vector<char> th(N);
		for (int n = 0; n < N; n++)
			cin >> th[n];

		for (int b = 0; b < N; b++)
		{
			if (th[b] == 'H')
				continue;

			sum += (1 << b);
		}

		bits[i] = sum;
	}

	vector<int> bit_case(N);
	for (int c = 0; c < (1 << N); c++)
	{
		for (int bm = 0; bm < N; bm++)
		{
			bit_case[bm] = c & (1 << bm) ? bits[bm] : ~bits[bm];
		}

		int t_count = 0;
		for (int col = 0; col < N; col++)
		{
			int col_t_count = 0;
			for (int row = 0; row < N; row++)
			{
				if (bit_case[row] & (1 << col))
					col_t_count++;
			}

			t_count += min(N - col_t_count, col_t_count);
		}

		answer = min(answer, t_count);
	}

	cout << answer;
	return 0;
}