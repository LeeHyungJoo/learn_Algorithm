#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    set<int> di_set;

    for (auto i : arr)
    {
        if (i % divisor == 0)
            di_set.insert(i);
    }

    if (di_set.empty())
        di_set.insert(-1);

    for (auto i : di_set)
    {
        answer.push_back(i);
    }

    return answer;
}