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
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>
#include <iostream>

using namespace std;


int heights[100][100];
int visited[100][100];

const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };


void DFS(int N, int dh, int y, int x)
{
	visited[y][x] = 1;

	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1)continue;
		if (visited[ny][nx]) continue;
		if (heights[ny][nx] > dh)
			DFS(N, dh, ny, nx);
	}
}


int main()
{
	int N = 0;
	cin >> N;

	set<int> dhs;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> heights[y][x];
			dhs.insert(heights[y][x]);
		}
	}

	int max_area = 1;
	for (auto dh : dhs)
	{
		int area_count = 0;

		for (int y = 0; y < N; y++)
			fill(visited[y], visited[y] + N, 0);

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (heights[y][x] > dh && visited[y][x] == 0)
				{
					DFS(N, dh, y, x);
					area_count++;
				}
			}
		}

		if (max_area < area_count)
			max_area = area_count;
	}

	cout << max_area;

	return 0;
}