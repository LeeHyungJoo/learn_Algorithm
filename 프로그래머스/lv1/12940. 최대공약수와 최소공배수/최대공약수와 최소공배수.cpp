#include <string>
#include <vector>

using namespace std;

int GCD(int n, int m)
{
    return m == 0 ? n : GCD(m, n % m);
}

vector<int> solution(int n, int m) {
    if (n < m)  swap(n, m);
    vector<int> answer;
    answer.push_back(GCD(n, m));
    answer.push_back((m * n) / answer[0]);
    return answer;
}