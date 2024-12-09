#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <numeric>
#include <list>

using namespace std;



int solution(vector<int> picks, vector<string> minerals) {
	unordered_map<string, int> types = { {"diamond", 0}, {"iron", 1}, {"stone", 2} };
	unordered_map<int, int> weights = { {0,25} , {1,5} , {2, 1} };
	unordered_map<int, unordered_map<int, int>> exhausted;
	exhausted[2][2] = 1;
	exhausted[2][1] = 5;
	exhausted[2][0] = 25;


	exhausted[1][2] = 1;
	exhausted[1][1] = 1;
	exhausted[1][0] = 5;

	exhausted[0][2] = 1;
	exhausted[0][1] = 1;
	exhausted[0][0] = 1;

	vector<int> mineral_types(minerals.size());
	vector<int> clustered(minerals.size() / 5 + (minerals.size() % 5 == 0 ? 0 : 1));
	int handled_cnt = picks[0] + picks[1] + picks[2];

	for (int i = 0; i < minerals.size(); i++)
	{
		if (handled_cnt * 5 - 1 < i)
			break;

		int type = types[minerals[i]];
		mineral_types[i] = type;
		clustered[i / 5] += weights[type];
	}

	map<int, list<int>, greater<int>> clustered_map;
	for (int i = 0 ; i < clustered.size() ; i++)
	{
		clustered_map[clustered[i]].push_back(i);
	}

	int answer = 0;
	int pick_type = 0;
	for (auto& cl : clustered_map)
	{
		for (auto index : cl.second)
		{
			while (true)
			{
				if (pick_type > 2)
					break;

				if (picks[pick_type] == 0)
					pick_type++;
				else
					break;
			}

			if (pick_type > 2)
				break;


			int end = min((index + 1) * 5, (int)minerals.size());
		
			for (int i = index * 5; i < end; i++)
			{
				answer += exhausted[pick_type][mineral_types[i]];
			}

			picks[pick_type]--;
		}
	}

	return answer;
}