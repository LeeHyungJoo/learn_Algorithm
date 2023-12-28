#include <string>
#include <vector>

using namespace std;

int dp[60000];

int Recursion(int target)
{
    if (target == 1)
        return 1;

    if (target == 2)
        return 2;

    if (dp[target] < 0)
    {
        dp[target] = Recursion(target - 1) % 1000000007 + Recursion(target - 2) % 1000000007;;
    }

    return dp[target] % 1000000007;
}

int solution(int n) {
    fill(dp, dp + 60000, -1);
    return Recursion(n) % 1000000007;
}