#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long sum[500000] = {};

long long solution(vector<int> sequence) {
    int size = sequence.size();

    sum[0] = sequence[0];
    for (int i = 1; i < size + 1; ++i)
        sum[i] = sum[i - 1] + (i & 1 ? -1  : +1) * sequence[i - 1];

    auto minmax = minmax_element(sum, sum + size + 1);
    return abs( minmax.first == minmax.second ?  *minmax.first : *minmax.first - *minmax.second);
}