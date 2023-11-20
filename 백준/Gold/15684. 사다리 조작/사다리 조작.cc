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

int answer = numeric_limits<int>::max();
int N, M, H;
int lined[30][10];


//i 번째가 i 번째로 가는지 체크. 
//사다리 combination 1개 넣는 모든 경우 ~~n개 놓는 모든 경우 놓을 때 마다 check. 

bool CheckRoute()
{
	for (int n = 0; n < N; n++)
	{
		int start = n;

		for (int h = 0; h < H; h++)
		{
			if (lined[h][start]) 
				start++;
			else if (start > 0 && lined[h][start - 1]) 
				start--;
		}

		if (start != n)
			return false;
	}

	return true;
}

void DFS(int h, int n, int cnt)
{
	if (cnt > 3)
		return;

	lined[h][n] = 1;

	if (CheckRoute())
		answer = min(answer, cnt);

	for (int y = h; y < H; y++)
	{
		for (int x = n - 1; x < N - 1; x++)
		{
			if (x< 0 || x > N - 1 || lined[y][x] || lined[y][x - 1] || lined[y][x + 1])
				continue;

			DFS(y, x, cnt + 1);
		}
	}

	lined[h][n] = 0;
}

int main()
{
	cin >> N >> M >> H;

	for (int m = 0; m < M; m++)
	{
		int y, x;
		cin >> y >> x;
		lined[y - 1][x - 1] = 1;
	}


	if (CheckRoute())
	{
		answer = min(answer, 0);
	}
	else
	{
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < N - 1; x++)
			{
				if (lined[y][x] || (x > 0 && lined[y][x - 1]) || (x < N - 1 && lined[y][x + 1]))
					continue;

				DFS(y, x, 1);
			}
		}
	}


	cout << (answer > 3 ? -1  : answer) << endl;
	return 0;
}