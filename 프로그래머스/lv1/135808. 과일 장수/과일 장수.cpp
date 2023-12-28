#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<int>());

    for (int c = 0; c < score.size() / m; c++)
        answer += score[(c + 1) * m - 1] * m;

    return answer;
}