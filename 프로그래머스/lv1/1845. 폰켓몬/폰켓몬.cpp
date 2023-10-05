#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> checks(nums.begin(), nums.end());
    return checks.size() > nums.size() / 2 ? nums.size() /2 : checks.size();
}