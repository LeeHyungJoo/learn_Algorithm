#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<int>());

    int r_idx = people.size() - 1;
    for (int idx = 0; idx < people.size(); idx++)
    {
        if (r_idx < idx)  break;
        if (people[idx] < limit && people[idx] + people[r_idx] <= limit)  r_idx--;

        answer++;
    }

    return answer;
}