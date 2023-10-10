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


bool Is666(int num)
{
	return string::npos != to_string(num).find("666");
}


int  main()
{
	int count;
	cin >> count;

	int start = 666;
	int answer = start;

	while (count != 0)
	{
		if (Is666(start))
		{
			count--;
			answer = start;
		}
		start++;
	}

	cout << answer;

	return 0;
}