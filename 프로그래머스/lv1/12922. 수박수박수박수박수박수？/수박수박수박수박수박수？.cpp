#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for (int idx = 0; idx < n / 2;idx++)
        answer.append("수박");
    if (n & 1) answer.append("수");
    return answer;
}