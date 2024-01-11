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

int M, N;
char chess[50][50];


int TakeMinCnt(int y, int x)
{
	int wCnt = 0, bCnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
		{
			char next = chess[i][j];

			if (i & 1)
				if (j & 1)
					next == 'W' ? bCnt++ : wCnt++;
				else
					next == 'B' ? bCnt++ : wCnt++;
			else
				if (j & 1)
					next == 'B' ? bCnt++ : wCnt++;
				else
					next == 'W' ? bCnt++ : wCnt++;
		}

	return min(wCnt, bCnt);
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> chess[i][j];

	int minval = 9999999;
	for (int i = 0; i < N - 8 + 1; i++)
		for (int j = 0; j < M - 8 + 1; j++)
			minval = min(TakeMinCnt(i, j), minval);

	cout << minval;
	return 0;
}