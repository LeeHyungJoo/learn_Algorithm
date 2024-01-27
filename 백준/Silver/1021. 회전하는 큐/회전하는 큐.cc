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
#include <deque>

using namespace std;

int N, M;

int main()
{
	cin >> N >> M;
	queue<int> q;
	for (int i = 0; i < M; i++)
	{
		int t;
		cin >> t;
		q.push(t);
	}

	deque<int> deq;
	for (int i = 0; i < N; i++)
		deq.push_back(i + 1);

	int answer = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		int idx = -1;
		for (int i = 0; i < deq.size(); i++)
		{
			if (cur == deq[i])
			{
				idx = i;
				break;
			}
		}

		if (idx < deq.size() - idx)
		{
			answer += idx;
			while (true)
			{
				int val = deq.front();
				deq.pop_front();
				if (val == cur)
					break;

				deq.push_back(val);
			}
		}
		else
		{
			answer += deq.size() - idx;
			while (true)
			{
				int val = deq.back();
				deq.pop_back();
				if (val == cur)
					break;

				deq.push_front(val);
			}
		}
	}

	cout << answer;
	return 0;
}