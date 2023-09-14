#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<int> que;
    map <int, int, greater<int>> checks;
    for (auto p : priorities)
    {
        que.push(p);
        checks[p]++;
    }

    int pop_count = 0;
    int loc = location + 1;
    while (!que.empty())
    {
        int greatest = checks.begin()->first;
        int val = que.front();
        que.pop();

        if (val == greatest)
        {
            //실행
            answer++;
            checks[greatest]--;
            if (checks.begin()->second == 0)
                checks.erase(checks.begin());
        }
        else
        {
            que.push(val);
        }

        if (++pop_count == loc)
        {
            pop_count = 0;
            loc = que.size();

            if (val == greatest)
                break;
        }
    }
    
    return answer;
}