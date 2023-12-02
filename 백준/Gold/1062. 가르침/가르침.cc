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
int statement_bits[50];

int checks[26];
int bitmask;
int answer = numeric_limits<int>::min();

void combi(int start_bit, int count)
{


	if (count >= K - 5)
	{
		int cnt = 0;
		for (int s_idx = 0; s_idx < N; s_idx++)
		{
			bool checked = true;
			for (int i = 0; i < 26; i++)
			{
				if ((statement_bits[s_idx] & checks[i]) && ((bitmask & checks[i]) == 0))
				{
					checked = false;
					break;
				}
			}
			if (checked)cnt++;
		}

		answer = max(cnt, answer);
	}
	else
	{
		for (int next_bit = start_bit + 1; next_bit < 26; next_bit++)
		{
			if (bitmask & checks[next_bit])
				continue;

			bitmask |= (checks[next_bit]);
			combi(next_bit, count + 1);

			if (next_bit != 'a' - 'a' && next_bit != 'n' - 'a' && next_bit != 't' - 'a' && next_bit != 'i' - 'a' && next_bit != 'c' - 'a')
				bitmask &= ~(checks[next_bit]);
		}
	}
}


int main()
{
	cin >> N >> K;

	for (int i = 0; i < 26; i++)
		checks[i] = (1 << i);


	for (int i = 0; i < N; i++)
	{
		string statement;
		cin >> statement;
		for (auto c : statement)
		{
			statement_bits[i] |= checks[c - 'a'];
		}
	}

	bitmask |= checks['a' - 'a'];
	bitmask |= checks['n' - 'a'];
	bitmask |= checks['t' - 'a'];
	bitmask |= checks['i' - 'a'];
	bitmask |= checks['c' - 'a'];

	if (K < 5)
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			combi(i, 0);
		}

		if (answer == numeric_limits<int>::min())
			answer = 0;
		cout << answer;
	}

	return 0;
}