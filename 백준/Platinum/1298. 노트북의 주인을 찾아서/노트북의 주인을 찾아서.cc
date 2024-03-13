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

vector<int> vtx[101];
int slt[101];
bool done[101];

bool dfs(int x) 
{
	for (int i = 0; i < vtx[x].size(); i++) 
	{
		int p = vtx[x][i];
		if (done[p]) 
            continue;
		done[p] = true;
		if (slt[p] == 0 || dfs(slt[p])) 
		{
			slt[p] = x;
			return true;
		}

	}
	return false;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vtx[a].push_back(b);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		fill(done, done + N + 1, false);
		if (dfs(i)) cnt++;
	}

	cout << cnt;
	return 0;
}