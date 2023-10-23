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

vector<int> trusted[10001];
int visited[10001] = {};
int N, M;

int answers[10001] = {};

int DFS(int idx )
{
	visited[idx] = 1;
	int count = 1;

	for (auto t_idx : trusted[idx])
	{
		if (visited[t_idx] == 1) continue;
		count += DFS(t_idx);
	}

	return count;
}

int main()
{
	cin >> N >> M;

	for (int m = 0; m < M; m++)
	{
		int to, from;
		cin >> from >> to;
		trusted[to].push_back(from);
	}

	int max_v = 0;
	for (int n = 0; n < N; n++)
	{
		fill(visited, visited + 10001, 0);
		int count = DFS(n + 1);
		if(max_v < count)
			max_v = count;
		answers[n + 1] = count;
	}

	for (int n = 0; n < N; n++)
		if(max_v == answers[n+1])
			cout << n+1 << ' ';

	return 0;
}