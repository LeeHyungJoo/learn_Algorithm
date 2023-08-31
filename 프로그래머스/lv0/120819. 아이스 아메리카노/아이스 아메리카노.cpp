#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    answer.resize(2,0);
    answer[0] = money / 5500;
    answer[1] = money % 5500;
    return answer;
}