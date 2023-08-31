#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    auto n_str = to_string(n);
    sort(n_str.begin(), n_str.end(), greater<char>());
    return atoll(n_str.c_str());
}