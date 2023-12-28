#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    multiset<int, greater<int>> checks;
    for (int idx = 0 ; idx < score.size() ; idx++)
    {
        checks.insert(score[idx]);
        if (checks.size() > k)
        {
            auto itr = checks.begin();
            advance(itr, k - 1);
            answer.push_back(*itr);
        }
        else
        {
            answer.push_back(*checks.rbegin());
        }
    }
    return answer;
}