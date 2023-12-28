#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
	vector<int> answer;
	answer.resize(targets.size(), -1);

	vector<unordered_map<char, int>> fixed_keymap;
	fixed_keymap.resize(keymap.size());
	for (int i = 0; i < keymap.size(); i++)
	{
		auto& km = fixed_keymap[i];
		for (int k_i = 0 ; k_i < keymap[i].size() ; k_i++)
		{
			auto itr = km.find(keymap[i][k_i]);
			if (itr != km.end())
				continue;

			km[keymap[i][k_i]] = k_i + 1;
		}
	}

	const int MAX = 1000;
	for (int idx = 0; idx < targets.size(); idx++)
	{
		bool failed = false;
		int key_count = 0;
		for (int t_idx = 0;t_idx < targets[idx].size(); t_idx++)
		{
			int min_idx = MAX;
			for (auto& fkm : fixed_keymap)
			{
				auto itr = fkm.find(targets[idx][t_idx]);
				if (itr != fkm.end())
				{
					min_idx = min(min_idx, itr->second);
				}
			}

			if (min_idx == MAX)
			{
				failed = true;
				break;
			}
			else
			{
				key_count += min_idx;
			}
		}

		answer[idx] = failed ?  -1 : key_count;
	}

	return answer;
}