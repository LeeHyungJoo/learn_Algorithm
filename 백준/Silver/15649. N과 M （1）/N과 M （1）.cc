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
int checks[10] = {};

void solution(int idx, vector<int>& selected)
{
	if (selected.size() == M)
	{
		for (auto s : selected)
			cout << s << ' ';
		cout << '\n';
		return;
	}

	for (int ni = 1 ; ni <= N ; ni++)
	{
		if (checks[ni] == 1) continue;
		checks[ni] = 1;
		selected.push_back(ni);
		solution(ni, selected);
		selected.pop_back();
		checks[ni] = 0;
	}
}

int main()
{
	cin >> N >> M;

	vector<int> selected;
	solution(0, selected);

	return 0;
}