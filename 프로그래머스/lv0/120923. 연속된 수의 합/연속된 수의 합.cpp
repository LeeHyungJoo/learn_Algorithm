#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;

    int start = start = (total / num) - (num / 2) + (total % num == 0 ? 0 : 1);

    for (int i = 0; i < num; i++)
    {
        answer.push_back(start++);
    }

    return answer;
}