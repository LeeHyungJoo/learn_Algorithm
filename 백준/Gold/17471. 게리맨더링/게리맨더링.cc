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
int graph[10];
int populations[10];


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> populations[i];

	for (int i = 0; i < N; i++)
	{
		int adj = 0;
		cin >> adj;
		for (int j = 0; j < adj; j++)
		{
			int target;
			cin >> target;
			graph[i] |= (1 << (target -1));
		}
	}

	int full_visited = (1 << N) - 1;
	for (int b_case = 0; b_case < (1 << N); b_case++)
	{
		if (b_case == 0 || b_case == (1 << N) - 1)
			continue;

		//1인경우, 0인 경우  각각 index 받기. 
		vector<int> indices(2,-1);
		for (int i = 0; i < N; i++)
		{
			if (indices[0] < 0 && b_case & (1 << i))
				indices[0] = i;
			if (indices[1] < 0 && !(b_case & (1 << i)))
				indices[1] = i;

			if(indices[0] >= 0 && indices[1] >=  0)
				break;
		}

		int b_visited = 0;
		int gap = 0;


		queue<int> idx_que;
		idx_que.push(indices[0]);
		while (!idx_que.empty())
		{
			auto cur = idx_que.front();
			idx_que.pop();

			if (b_visited & (1 << cur))
				continue;

			b_visited |= (1 << cur);
			gap += populations[cur];

			for (int i = 0; i < N; i++)
			{
				if ((graph[cur] & (1 << i)) && (b_case & (1<< i)))
				{
					idx_que.push(i);
				}
			}
		}

		idx_que.push(indices[1]);
		while (!idx_que.empty())
		{
			auto cur = idx_que.front();
			idx_que.pop();

			if (b_visited & (1 << cur))
				continue;

			b_visited |= (1 << cur);
			gap -= populations[cur];

			for (int i = 0; i < N; i++)
			{
				if (graph[cur] & (1 << i) && !(b_visited & (1 << i)))
				{
					idx_que.push(i);
				}
			}
		}

		if(b_visited == full_visited)
			answer = min(abs(gap), answer);
	}

	cout << (answer == numeric_limits<int>::max() ? -1 : answer);

	return 0;
}