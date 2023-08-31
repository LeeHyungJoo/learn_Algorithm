#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    answer.resize(phone_number.size(), '*');
    for (int r_idx = 0; r_idx < 4; r_idx++)
        answer[answer.size() - r_idx - 1] = phone_number[answer.size() - r_idx - 1];
    return answer;
}