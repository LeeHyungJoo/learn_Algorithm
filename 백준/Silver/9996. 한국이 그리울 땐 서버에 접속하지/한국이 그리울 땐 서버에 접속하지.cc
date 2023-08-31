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

	int file_count = 0;
	cin >> file_count;

	string expr;
	cin >> expr;

	auto delimeter = expr.find('*');
	string tokens[2]{ "","" };

	if (delimeter != 0)
		tokens[0] = expr.substr(0, delimeter);

	if (delimeter + 1 < expr.size())
		tokens[1] = expr.substr(delimeter + 1, expr.size());

	bool* checks = new bool[file_count] {false};
	string file_name;
	for (int i = 0; i < file_count; i++)
	{
		cin >> file_name;
		checks[i] = (file_name.size() >= tokens[0].size() + tokens[1].size()) &&
			(tokens[0].empty() ? true : file_name.find(tokens[0]) == 0) &&
			(tokens[1].empty() ? true : file_name.rfind(tokens[1]) == file_name.size() - tokens[1].size());
	}

	for (int count = 0 ; count < file_count ; count++)
		cout << (checks[count] ? "DA" : "NE") << endl;

	return 0;
}