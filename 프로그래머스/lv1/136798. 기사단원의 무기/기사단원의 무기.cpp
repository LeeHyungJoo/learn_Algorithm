#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int ironWeight = 0;

    for (int i = 1; i <= number; i++) {
        int divisors = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                divisors += 2;
                if (j * j == i) {
                    divisors--;
                }
            }
        }
        int attackPower = (divisors > limit) ? power : divisors;
        ironWeight += attackPower;
    }

    return ironWeight;
}
