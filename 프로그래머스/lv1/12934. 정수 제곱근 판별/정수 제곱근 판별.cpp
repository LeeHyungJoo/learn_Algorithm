#include <string>
#include <vector>
#include <math.h>
#include <numeric>
using namespace std;

long long solution(long long n) {
    auto candidate = sqrtl(n);
    if (candidate - static_cast<long long>(candidate) > numeric_limits<long double>::epsilon())
        return -1;
    return pow(candidate + 1, 2);
}