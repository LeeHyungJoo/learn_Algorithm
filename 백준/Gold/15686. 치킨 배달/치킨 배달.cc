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

int N, M;
vector<pair<int, int>> chicken_houses;
vector<pair<int, int>> citizen_houses;
vector<int> chicken_house_indices;
int min_dist = numeric_limits<int>::max();

void GetChickenDist(int idx)
{
	if (chicken_house_indices.size() == M)
	{
		int dist = 0;

		for (auto& citizen : citizen_houses)
		{
			int min_dist_citizen = numeric_limits<int>::max();
			for (auto chicken : chicken_house_indices)
			{
				min_dist_citizen = min(abs(chicken_houses[chicken].first - citizen.first) + abs(chicken_houses[chicken].second - citizen.second), min_dist_citizen);
			}
			dist += min_dist_citizen;
		}

		min_dist = min(min_dist, dist);
	}

	for (int ch_idx = idx + 1; ch_idx < chicken_houses.size(); ch_idx++)
	{
		chicken_house_indices.push_back(ch_idx);
		GetChickenDist(ch_idx);
		chicken_house_indices.pop_back();
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int t;
			cin >> t;
			switch (t)
			{
			case 1:
				citizen_houses.push_back(make_pair(i + 1, j + 1));
				break;
			case 2:
				chicken_houses.push_back(make_pair(i + 1, j + 1));
				break;
			}
		}
	}

	GetChickenDist(-1);

	cout << min_dist;

	return 0;
}