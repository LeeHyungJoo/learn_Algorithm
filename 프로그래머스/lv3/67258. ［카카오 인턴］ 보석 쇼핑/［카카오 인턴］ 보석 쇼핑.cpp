#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <list>
#include <numeric>

using namespace std;

vector<int> solution(vector<string> gems)
{
	int gems_size = static_cast<int>(gems.size());
	vector<int> answer = { 0, gems_size };

	set<string> check;
	check.insert(gems.begin(), gems.end());

	int gems_type_size = check.size();
	check.clear();

	list<pair<int, int>> range_list;
	int start_idx = 0;
	for (int fwd_idx = 0; fwd_idx < gems_size; fwd_idx++)
	{
		check.insert(gems[fwd_idx]);

		if (check.size() == gems_type_size)
		{
			check.clear();
			for (int rvs_idx = fwd_idx; rvs_idx != start_idx; rvs_idx--)
			{
				check.insert(gems[rvs_idx]);
				if (check.size() == gems_type_size)
				{
					start_idx = rvs_idx;
					break;
				}
			}
			check.clear();

			range_list.push_back(make_pair(start_idx, fwd_idx));
			fwd_idx = start_idx + 1;
		}
	}

	for (auto range : range_list)
	{
		auto gap = range.second - range.first;
		if (gap < answer[1] - answer[0])
		{
			answer[0] = range.first;
			answer[1] = range.second;
		}
	}

	answer[0] += 1;
	answer[1] += 1;

	return answer;
}
