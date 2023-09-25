#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
	for (int y = 1; y < land.size(); y++)
	{
		int last = y - 1;
		land[y][0] = land[y][0] + max(land[last][1], max(land[last][2], land[last][3]));
		land[y][1] = land[y][1] + max(land[last][0], max(land[last][2], land[last][3]));
		land[y][2] = land[y][2] + max(land[last][0], max(land[last][1], land[last][3]));
		land[y][3] = land[y][3] + max(land[last][0], max(land[last][1], land[last][2]));
	}

    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());;
}