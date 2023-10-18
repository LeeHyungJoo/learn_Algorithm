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


int  main()
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << '\n';
		}
		else
		{
			double dist = abs(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));

			if (r1 + r2 == dist || abs(r1 - r2) == dist)
			{
				cout << 1 << '\n';
			}
			else if( r1 + r2 < dist || dist < abs(r1 - r2))
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 2 << '\n';
			}
		}
	}

	return 0;
}