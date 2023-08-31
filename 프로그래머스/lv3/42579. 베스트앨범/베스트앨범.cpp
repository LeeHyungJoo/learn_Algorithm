#include <string>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	unordered_map<string, map<int/*play*/, list<int/*idx*/>, greater<int>>> priority_map_by_genre;
	unordered_map<string, int> genre_sum_map;
	
	for (int idx = 0; idx < plays.size(); idx++)
	{
		auto& g_str = genres[idx];
		auto p_count = plays[idx];
		auto& map_in_genre = priority_map_by_genre[g_str];

		map_in_genre[p_count].push_back(idx);
		genre_sum_map[g_str] += p_count;
	}

	map<int, string, greater<int>> genres_sorted_map;
	for (auto& genre_sum : genre_sum_map)
	{
		genres_sorted_map[genre_sum.second] = genre_sum.first;
	}

	vector<int> answer;
	for (auto& genre_sort : genres_sorted_map)
	{
		const auto& play_list_map = priority_map_by_genre[genre_sort.second];
		auto check_top = [&]() -> void
		{
			int top_count = 0;
			for (auto play_list : play_list_map)
			{
				for (auto play : play_list.second)
				{
					if (top_count == 2)
					{
						return;
					}

					top_count++;
					answer.push_back(play);
				}
			}
		};

		check_top();
	}

	return answer;
}