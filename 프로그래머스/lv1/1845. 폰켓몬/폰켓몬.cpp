#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> checks;
    for (auto n : nums)
        checks.insert(n);
    return checks.size() > nums.size() / 2 ? nums.size() /2 : checks.size();
}