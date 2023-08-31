#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    map<int, int, greater<int>> checks;

    for (auto em : emergency)
        checks[em] = 0;

    int idx = 0;
    for (auto& check : checks)
        check.second = ++idx;

    for (auto em : emergency)
    {
        answer.push_back(checks[em]);
    }

    return answer;
}