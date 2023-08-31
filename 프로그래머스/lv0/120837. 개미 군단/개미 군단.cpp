#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;

    int a = hp / 5;
    answer += a;
    hp -= a * 5;

    int b = hp / 3;
    answer += b;
    hp -= b * 3;

    return answer + hp;
}