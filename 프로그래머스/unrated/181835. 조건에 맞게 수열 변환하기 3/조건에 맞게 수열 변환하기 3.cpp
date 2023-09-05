#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    if (k & 1) for (auto& i : arr) i *= k;
    else  for (auto& i : arr) i += k;
    return arr;
}