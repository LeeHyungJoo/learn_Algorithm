#include <string>
#include <vector>
#include <map>

using namespace std;

string bab_map[4] = { "aya", "ye", "woo", "ma" };


int solution(vector<string> babbling) {
	int answer = babbling.size();


	for (auto& b : babbling)
	{
		int caret = 0;
		int last_bab = -1;
		bool failed = false;

		while (true)
		{
			map<int, int> check;
			for (int i = 0; i < 4; i++)
			{
				if (last_bab != -1 && last_bab == i)
					continue;

				auto f = b.find(bab_map[i],caret);
				if (f != b.npos)
				{
					check[f] = i;
				}
			}

			if (check.empty())
			{
				failed = true;
				break;
			}

			auto itr = check.begin();
			if (caret != itr->first)
			{
				failed = true;
				break;
			}

			last_bab = itr->second;
			caret = itr->first + bab_map[itr->second].size();
			if (caret == b.size())
				break;
		}

		if (failed)
			answer--;
	}

	return answer;
}