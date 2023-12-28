#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> checks;
    for (auto cloth : clothes)
    {
        checks[cloth[1]]++;
    }

    int answer = 1;
    for (auto c : checks)
    {
        answer *= (c.second + 1);
    }

    return answer -1;
}