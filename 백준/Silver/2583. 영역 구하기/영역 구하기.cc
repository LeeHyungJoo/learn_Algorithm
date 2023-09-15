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

int maps[100][100] = {};
bool visited[100][100] = {};

const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };


int Search(int Y, int X, int y, int x)
{
	int area = 1;

	visited[y][x] = true;

	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny > Y - 1 || nx< 0 || nx > X - 1) continue;
		if (visited[ny][nx] || maps[ny][nx] == 1) continue;

		area += Search(Y, X, ny, nx);
	}

	return area;
}


int main()
{
	int Y, X, K;
	cin >> Y >> X >> K;

	for (int k = 0; k < K; ++k)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		//맵 세팅
		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				maps[y][x] = 1;
	}
	vector<int> areas;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (visited[y][x] || maps[y][x] == 1)
				continue;

			areas.push_back(Search(Y, X, y, x));
		}
	}
	sort(areas.begin(), areas.end());

	cout << areas.size() << endl;
	for (auto area : areas)
		cout << area << " ";
	return 0;
}