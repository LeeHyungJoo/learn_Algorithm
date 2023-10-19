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

using namespace std;


struct Point
{
public:
	Point() :x(0), y(0) {}
	Point(int x, int y)
		:x(x), y(y)
	{}

	Point operator+ (const Point& rhs)
	{
		return Point(x + rhs.x, y + rhs.y);
	}


public:
	int x;
	int y;
};

unordered_map<int, Point> checks;

int  main()
{
	int c;
	cin >> c;

	checks[0] = Point( 1,0 );
	checks[1] = Point( 0,1 );
	for (int i = 2; i <= 40; i++)
	{
		checks[i] = checks[i - 2] + checks[i - 1];
	}


	for (int i = 0; i < c; i++)
	{
		int n;
		cin >> n;
		
		cout << checks[n].x << ' ' << checks[n].y << '\n';
	}

	return 0;
}