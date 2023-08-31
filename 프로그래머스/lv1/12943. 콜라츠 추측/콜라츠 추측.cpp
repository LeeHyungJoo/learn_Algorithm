#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;

    long long num_l = num;
    while (answer <= 500)
    {
        if (num_l == 1)
            break;

        if (num_l % 2 == 0)
            num_l >>= 1;
        else
            num_l = num_l * 3 + 1;

        answer++;
    }

    if (answer > 500 && num_l != 1)
        answer = -1;

    return answer;
}