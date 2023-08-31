#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	cin >> input;

	vector<int> alpha_count;
	alpha_count.resize(26);

	for (auto c : input)
	{
		alpha_count[c - 'a']++;
	}

	for (auto ac : alpha_count)
	{
		cout << ac << " ";
	}

	return 0;
}