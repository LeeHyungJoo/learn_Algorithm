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

stack<int> nums;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int c, arg;
	for (int i = 0; i < N; i++)
	{
		cin >> c;

		switch (c)
		{
		case 1:
			cin >> arg;
			nums.push(arg);
			break;
		case 2:
			if (nums.empty())
				cout << -1 << '\n';
			else
			{
				cout << nums.top()<< '\n';
				nums.pop();
			}
			break;
		case 3:
			cout << nums.size() << '\n';
			break;
		case 4:
			cout << (nums.empty() ? 1 : 0) << '\n';
			break;
		case 5:
			if (nums.empty())
				cout << -1 << '\n';
			else
				cout << nums.top() << '\n';
			break;
		}
	}

	return 0;
}