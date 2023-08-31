#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<int, float>> failed_ratios;

    for (int i = 0; i < N; i++)
    {
        int uncleared = 0;
        int cleared = 0;
        for (auto stage : stages)
        {
            if (i + 1 == stage)
                uncleared++;
            else if (i + 1 < stage)
                cleared++;
        }
        
        if (cleared == 0)
        {
            if (uncleared == 0)
            {
                failed_ratios.push_back(make_pair(i + 1, 0.0f));
            }
            else
            {
                failed_ratios.push_back(make_pair(i + 1, static_cast<float>(uncleared)));
            }
        }
        else
        {
            failed_ratios.push_back(make_pair(i + 1, static_cast<float>(uncleared) / cleared));
        }
    }

    sort(failed_ratios.begin(), failed_ratios.end(),
        [](const pair<int, float>& lhs, const pair<int, float>& rhs)->bool
        {
            if (lhs.second > rhs.second)
            {
                return true;
            }
            else if (lhs.second == rhs.second && lhs.first < rhs.first)
            {
                return true;
            }
            return false;
        }
    );

    for (auto failed_ratio : failed_ratios)
    {
        answer.push_back(failed_ratio.first);
    }

    return answer;
}