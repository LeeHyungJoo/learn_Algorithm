#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int idx = 0; idx < signs.size();idx++)
        answer += absolutes[idx] * (signs[idx] ? +1 : -1);
    return answer;
}