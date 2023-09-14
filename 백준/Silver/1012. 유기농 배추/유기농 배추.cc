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


int farm[50][50];
int visited[50][50];

const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };

void Search(int N, int M, int y, int x)
{
	visited[y][x] = 1;

	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny > N - 1) continue;
		if (nx < 0 || nx > M - 1) continue;

		if (visited[ny][nx]) continue;
		if (farm[ny][nx] == 0)continue;

		Search(N, M, ny, nx);
	}
}


int main()
{
	int tc = 0;
	cin >> tc;

	vector<int> answers;
	for (int t = 0; t < tc; t++)
	{
		int M, N, K;
		cin >> M >> N >> K;

		for (int n = 0; n < N; n++)
			fill(farm[n], farm[n] + M, 0);

		for (int n = 0; n < N; n++)
			fill(visited[n], visited[n] + M, 0);

		for (int lk = 0; lk < K; lk++)
		{
			int m, n;
			cin >> m >> n;
			farm[n][m] = 1;
		}

		int area_max = 0;
		for(int y = 0 ; y < N ; y++)
			for(int x= 0 ; x < M ; x++)
				if (visited[y][x] == 0 && farm[y][x] == 1)
				{
					Search(N, M, y, x);
					area_max++;
				}
		answers.push_back(area_max);
	}
	
	for (auto a : answers)
		cout << a << endl;
	return 0;
}