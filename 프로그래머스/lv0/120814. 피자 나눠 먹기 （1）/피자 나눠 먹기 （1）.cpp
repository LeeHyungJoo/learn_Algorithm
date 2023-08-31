#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    answer += static_cast<int>(n/7) + ((n%7) > 0 ? 1 : 0);
    return answer;
}