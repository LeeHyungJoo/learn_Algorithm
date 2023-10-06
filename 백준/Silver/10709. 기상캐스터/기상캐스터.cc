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

int w_map[100][100];

int  main()
{
	int H, W;
	cin >> H >> W;

	for (int h = 0; h < H; h++)
		fill(w_map[h], w_map[h] + W, -1);

	for (int h = 0; h < H; h++)
	{
		int minute = -1;
		for (int w = 0; w < W; w++)
		{
			if (minute >= 0)
				minute++;

			char ch;
			cin >> ch;

			if (ch == 'c')
			{
				minute = 0;
			}

			cout << minute << " ";
		}
		cout << endl;
	}

	return 0;
}