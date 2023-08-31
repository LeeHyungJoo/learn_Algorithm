#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    for (auto c : to_string(n))
        answer.push_back(atoi(&c));
    reverse(answer.begin(), answer.end());

    return answer;
}