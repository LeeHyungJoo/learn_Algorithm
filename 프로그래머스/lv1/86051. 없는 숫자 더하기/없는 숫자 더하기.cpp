#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> numbers) {
    set<int> checks;
    checks.insert(numbers.begin(), numbers.end());

    int answer = 0;
    for (int num = 0; num < 10; num++)
        if (checks.insert(num).second == true)
            answer += num;
    return answer;
}