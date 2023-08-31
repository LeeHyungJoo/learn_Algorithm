#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    answer.resize(score.size());

    map<int/*value*/, vector<int/*vector idx*/>, greater<int>> values;
    for (int i = 0; i < score.size(); i++)
    {
        values[score[i][0] + score[i][1]].push_back(i);
    }

    int rank = 1;
    for (auto value : values)
    {
        for (auto tie_rank : value.second)
            answer[tie_rank] = rank;
        rank += value.second.size();
    }

    return answer;
}