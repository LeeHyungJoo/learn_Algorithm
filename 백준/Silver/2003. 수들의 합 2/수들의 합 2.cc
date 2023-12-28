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

int N, M;
int s, e;
int nums[10000];

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	int cnt = 0;
	int sum = nums[s];
	while (e < N)
	{
		if (sum == M)
		{
			sum -= nums[s++];
			sum += nums[++e];
			cnt++;
		}
		else if (sum < M)
			sum += nums[++e];
		else
			sum -= nums[s++];
	}

	cout << cnt << endl;
	return 0;
}