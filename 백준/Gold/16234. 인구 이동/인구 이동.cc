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

int N, L, R;
int terrain[50][50] = {};
int visited[50][50] = {};

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };


void DFS(int y, int x, vector<pair<int, int>>& coords, int& population_sum, int& asso_count)
{
	visited[y][x] = 1;

	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;

		if (visited[ny][nx] == 1)
			continue;

		auto gap = abs(terrain[y][x] - terrain[ny][nx]);
		if (gap < L || gap > R)
			continue;

		if (coords.empty())
		{
			coords.push_back(make_pair(y, x));
			asso_count++;
			population_sum += terrain[y][x];
		}

		coords.push_back(make_pair(ny, nx));
		asso_count++;
		population_sum += terrain[ny][nx];

		DFS(ny, nx, coords, population_sum, asso_count);
	}
}


int solution()
{
	int days = 0;
	while (true)
	{
		vector<vector<pair<int, int>>> coords_set;
		vector<int> populations;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (visited[y][x] == 1)
					continue;

				vector<pair<int, int>> coords;
				int population = 0 , asso_count = 0 ;
				DFS(y, x, coords, population , asso_count);

				if (coords.empty())
					continue;

				coords_set.push_back(coords);
				populations.push_back(population / asso_count);
			}
		}

		if (coords_set.empty())
			break;

		for (int i =0 ; i < coords_set.size(); i++)
		{
			const auto& coords = coords_set[i];
			int fixed_population = populations[i];

			for (const auto& coord : coords)
			{
				terrain[coord.first][coord.second] = fixed_population;
			}
		}

		for (int v_i = 0; v_i < N; v_i++)
			fill(visited[v_i], visited[v_i] + N, 0);

		days++;
	}


	return days;
}

int main()
{
	cin >> N >> L >> R;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> terrain[y][x];
		}
	}

	cout << solution();
	return 0;
}