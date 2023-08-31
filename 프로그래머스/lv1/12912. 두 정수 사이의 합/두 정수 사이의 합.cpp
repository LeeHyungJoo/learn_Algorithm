#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int a, int b) {
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}
