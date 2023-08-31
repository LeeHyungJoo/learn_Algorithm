#include <string>
#include <vector>
#include <numeric>

using namespace std;

int rotate(vector<vector<int>>& tiles, vector<int> query)
{
	int y1 = query[0] - 1, x1 = query[1] - 1;
	int y2 = query[2] - 1, x2 = query[3] - 1;

	int next = tiles[y1][x1];
	int min = numeric_limits<int>::max();

	//→
	for (int x = x1 + 1; x <= x2; x++)
	{
		int temp = tiles[y1][x];
		tiles[y1][x] = next;
		if (next < min)
			min = next;
		next = temp;
	}

	//↓
	for (int y = y1 + 1; y <= y2; y++)
	{
		int temp = tiles[y][x2];
		tiles[y][x2] = next;
		if (next < min)
			min = next;
		next = temp;
	}

	//←
	for (int x = x2 - 1; x >= x1; x--)
	{
		int temp = tiles[y2][x];
		tiles[y2][x] = next;
		if (next < min)
			min = next;
		next = temp;
	}

	//↑
	for (int y = y2 - 1; y >= y1; y--)
	{
		int temp = tiles[y][x1];
		tiles[y][x1] = next;
		if (next < min)
			min = next;
		next = temp;
	}

	if (next < min)
		min = next;

	return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;

	vector<vector<int>> tiles;
	tiles.resize(rows);

	int val = 1;
	for (int r = 0; r < rows; r++)
	{
		tiles[r].resize(columns);
		for (int c = 0; c < columns; c++)
			tiles[r][c] = val++;
	}

	for (auto query : queries)
	{
		answer.push_back(rotate(tiles, query));
	}

	return answer;
}