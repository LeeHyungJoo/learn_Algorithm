#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    unordered_map<char, int> skill_tree_map;
    for (int i = 0 ; i <skill.size() ; i++)
        skill_tree_map[skill[i]] = i;

    for (auto skt : skill_trees)
    {
        bool check = true;
        int last_idx = -1;

        for (int i = 0; i < skt.size(); i++)
        {
            auto itr = skill_tree_map.find(skt[i]);
            if (itr == skill_tree_map.end())
                continue;

            if (last_idx + 1 != itr->second)
            {
                check = false;
                break;
            }

            last_idx = itr->second;
        }

        if (check)
            answer++;
    }


    return answer;
}