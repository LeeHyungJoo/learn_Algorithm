#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    return ((k-1) * 2) % numbers.size() + 1;
}