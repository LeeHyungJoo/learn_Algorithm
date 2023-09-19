#include <string>
#include <vector>

using namespace std;

struct Coord
{
	Coord() :x(0), y(0) {}
	int x;
	int y;

	void operator+= (const Coord& lhs)
	{
		x += lhs.x;
		y += lhs.y;
	}

}coord;

vector<int> solution(vector<string> park, vector<string> routes) {
	int H = park.size(), W = park[0].size();

	for (int h = 0; h < H; h++)
	{
		for (int w = 0; w < W; w++)
		{
			if (park[h][w] == 'S') 
			{
				coord.y = h;
				coord.x = w;
				break;
			}
		}
	}

	for (auto route : routes)
	{
		char op = route.substr(0, 1).c_str()[0];
		int dist = atoi(route.substr(2, route.size()).c_str());

		Coord dir;
		switch (op)
		{
		case 'N':
			dir.y = -1;
			break;
		case 'S':
			dir.y = +1;
			break;
		case 'W':
			dir.x = -1;
			break;
		case 'E':
			dir.x = +1;
			break;
		}

		bool bFailed = false;
		Coord check = coord;
		for (int d = 0; d < dist; d++)
		{
			check += dir;

			if (check.x < 0 || check.x > W - 1 || check.y < 0 || check.y > H - 1)
			{
				bFailed = true;
				break;
			}

			if (park[check.y][check.x] == 'X')
			{
				bFailed = true;
				break;
			}

		}

		if (bFailed)
			continue;

		coord = check;
	}

	return { coord.y, coord.x };
}