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
int values[200][200];
int aread[200][200];
vector<pair<int, int>> selected;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool AreaCheck(int y, int x)
{
	if (aread[y][x] > 0)
		return false;

	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
			return false;

		if (aread[ny][nx] > 0)
			return false;
	}

	return true;
}

void Plant(int y, int x)
{
	aread[y][x] = 1;
	for (int d = 0; d < 4; d++)
		aread[y + dy[d]][x + dx[d]] = 1;

	selected.push_back({ y,x });
}

void Unplant(int y, int x)
{
	aread[y][x] = 0;
	for (int d = 0; d < 4; d++)
		aread[y + dy[d]][x + dx[d]] = 0;

	selected.pop_back();
}


void DFS(int y, int x)
{
	Plant(y, x);

	if (selected.size() == 3)
	{
		int sum = 0;
		for (const auto& s : selected)
		{
			sum += values[s.first][s.second];
			for (int d = 0; d < 4; d++)
				sum += values[s.first + dy[d]][s.second +dx[d]];
		}

		answer = min(sum, answer);
	}
	else
	{
		for (int ny = 0; ny < N; ny++)
		{
			for (int nx = 0; nx < N; nx++)
			{
				if (!AreaCheck(ny, nx))
					continue;

				DFS(ny, nx);
			}
		}
	}

	Unplant(y, x);
}

int main()
{
	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> values[y][x];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (!AreaCheck(y, x))
				continue;

			DFS(y, x);
		}
	}

	cout << answer << endl;

	return 0;
}