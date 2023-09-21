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


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> num_list(N, 0);
	unordered_map<int, int> count_map;
	unordered_map<int, int> ordered_map;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		num_list[i] = t;
		count_map[t]++;
		auto itr = ordered_map.find(t);
		if (itr == ordered_map.end())
			ordered_map[t] = i;
	}

	sort(num_list.begin(), num_list.end(), [&count_map, &ordered_map](const int& lhs, const int& rhs) {

		int lhs_count = count_map[lhs], rhs_count = count_map[rhs];

		if (lhs_count == rhs_count)
			return ordered_map[lhs] < ordered_map[rhs];

		return lhs_count > rhs_count;
		});

	for (auto num : num_list)
		cout << num << " ";

	return 0;
}