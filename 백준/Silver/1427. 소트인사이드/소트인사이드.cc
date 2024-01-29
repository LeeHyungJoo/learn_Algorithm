#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

string str;
map<char, int, greater<int>> checks;

int main()
{
	cin >> str;

	for (auto ch : str)
		checks[ch]++;

	string answer;
	for (auto& ch : checks)
		answer += string(ch.second, ch.first);

	cout << answer;
	return 0;
}