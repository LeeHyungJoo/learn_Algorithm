#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <chrono>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int count = 0;
	cin >> count;

	vector<string> player_names;
	player_names.resize(count);

	map<char, int> first_char_count;
	for (int idx = 0; idx < count; idx++)
	{
		cin >> player_names[idx];
		first_char_count[player_names[idx][0]]++;
	}

	string ret;
	for (auto fcc : first_char_count)
	{
		if (fcc.second < 5)
			continue;

		ret.push_back(fcc.first);
	}

	if (ret.empty())
		ret = "PREDAJA";

	cout << ret;
	return 0;
}