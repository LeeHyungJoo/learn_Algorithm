#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> scoville, int K) {
    multiset<int> checks;
    for (auto s : scoville)
        checks.insert(s);

    int answer = 0;
    while (true)
    {
        auto t1 = checks.begin();
        if (*checks.begin() >= K)
        {
            break;
        }

        if (checks.size() == 1)
        {
            answer = -1;
            break;
        }

        auto t1_v = *t1;
        auto t2 = checks.erase(t1);
        if (t2 == checks.end())
        {
            answer = -1;
            break;
        }
        auto t2_v = *t2;
        checks.erase(t2);

        int sco = t1_v + (t2_v * 2);
        checks.insert(sco);
        answer++;
    }


    return answer;
}