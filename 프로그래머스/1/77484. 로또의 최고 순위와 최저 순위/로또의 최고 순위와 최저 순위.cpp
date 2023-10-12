#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int,int> win_map = { {6,1} ,{5,2},{4,3},{3,4},{2,5} };

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	answer.resize(2, 6);

	int wc = 0;
	int low_cnt = 0;
	for (int idx = 0; idx < win_nums.size();idx++)
	{
		if (lottos[idx] == 0)
		{
			wc++;
		}

		if(find(lottos.begin(), lottos.end(), win_nums[idx]) != lottos.end())
		{
			low_cnt++;
		}
	}

	auto l_itr = win_map.find(low_cnt);
	if (l_itr != win_map.end())
		answer[1] = l_itr->second;

	auto w_itr = win_map.find(low_cnt + wc);
	if (w_itr != win_map.end())
		answer[0] = w_itr->second;

	return answer;
}