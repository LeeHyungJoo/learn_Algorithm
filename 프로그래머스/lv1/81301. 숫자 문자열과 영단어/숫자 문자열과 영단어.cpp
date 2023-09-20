#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
	unordered_map<char, unordered_map<string, char>> check_map;
	check_map['z']["zero"] = '0';
	check_map['o']["one"] = '1';
	check_map['t']["two"] = '2';
	check_map['t']["three"] = '3';
	check_map['f']["four"] = '4';
	check_map['f']["five"] = '5';
	check_map['s']["six"] = '6';
	check_map['s']["seven"] = '7';
	check_map['e']["eight"] = '8';
	check_map['n']["nine"] = '9';

	string result;
	for (int idx = 0; idx < s.size(); idx++)
	{
		if (isdigit(s[idx])) result.push_back(s[idx]);

		auto f_itr = check_map.find(s[idx]);
		if (f_itr == check_map.end())
			continue;

		for (const auto& numstr : f_itr->second)
		{
			if (numstr.first != s.substr(idx, numstr.first.size()))
				continue;

			result.push_back(numstr.second);
			break;
		}
	}

	return atoi(result.c_str());
}