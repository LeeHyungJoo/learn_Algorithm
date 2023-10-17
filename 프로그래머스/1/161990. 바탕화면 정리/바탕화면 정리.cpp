#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;

	int ldx = 0, ldy = 0;
	int rux = 50, ruy = 50;

	for (int y = 0; y < wallpaper.size(); y++)
	{
		for (int x = 0; x < wallpaper[y].size(); x++)
		{
			if (wallpaper[y][x] == '#')
			{
				if (ldx < x)
					ldx = x;
				if (rux > x)
					rux = x;
				if (ldy < y)
					ldy = y;
				if (ruy > y)
					ruy = y;
			}
		}
	}

	return { ruy, rux, ldy + 1,ldx + 1 };
}