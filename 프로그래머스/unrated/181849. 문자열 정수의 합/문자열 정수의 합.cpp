#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(string num_str) {
    return  accumulate(num_str.begin(), num_str.end(),  '0' * -1 * num_str.size());
}