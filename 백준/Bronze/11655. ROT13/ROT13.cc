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

	string str;
	getline(cin, str);

	for (auto& ch : str)
	{
		if (!isalpha(ch)) continue;

		int ch_overflow = ch + 13;
		if ('z' < ch_overflow)
			ch = 'a' + ch_overflow - 'z' - 1;
		else if ('Z' < ch_overflow && ch_overflow <= 'Z' + 13)
			ch = 'A' + ch_overflow - 'Z' - 1;
		else
			ch += 13;
	}

	cout << str;
	return 0;
}