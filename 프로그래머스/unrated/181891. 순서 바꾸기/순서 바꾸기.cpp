#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    auto t = vector<int>(num_list.begin() + n, num_list.end());
    t.insert(t.end(), num_list.begin(), num_list.begin() + n);
    return t;
}