#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delimeter = ' ')
{
	vector<string> ret;
	int start_idx = 0;
	for (int idx = start_idx; idx < str.size(); idx++)
	{
		if (idx == str.size() - 1)
		{
			auto split_str = str.substr(start_idx, str.size());
			if (!split_str.empty())
				ret.push_back(split_str);
		}

		if (str[idx] != delimeter)
			continue;

		auto split_str = str.substr(start_idx, idx - start_idx);
		if (!split_str.empty())
			ret.push_back(split_str);

		start_idx = idx + 1;
	}

	return ret;
}


vector<string> solution(string my_string) {
	return split(my_string);
}