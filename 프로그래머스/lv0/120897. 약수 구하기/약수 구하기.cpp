#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for (int i = 0; i < n; i++)
        if (n % (i + 1) == 0)
            answer.push_back(i + 1);
    return answer;
}