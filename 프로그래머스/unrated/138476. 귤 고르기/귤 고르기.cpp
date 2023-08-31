#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> type_count;
    for (auto t : tangerine) type_count[t]++;

    map<int, int, greater<int>> count_type;
    for (auto tc : type_count) count_type[tc.second]++;

    int answer = 0;
    for (auto ct : count_type)
    {
        auto c = ct.second;
        while (c != 0)
        {
            answer++;
            k -= ct.first;
            if (k <= 0) break;
            c--;
        }
        if (k <= 0) break;
    }

    return answer;
}