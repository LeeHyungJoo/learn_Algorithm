#include <string>
#include <vector>

using namespace std;

int dp[101][101] = {};


int RecursionCheck(const int& N, const int& M, int y, int x)
{
	if (dp[y][x] < 0)
		return 0;

	if (y == 0 || x == 0 || N < y || M < x)
		return 0;

	if (dp[y][x] == 0)
	{
		dp[y][x] = (RecursionCheck(N, M, y - 1, x) + RecursionCheck(N, M, y, x - 1)) % 1000000007;
	}

	return dp[y][x] % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
	dp[1][2] = 1;
	dp[2][1] = 1;
	for (auto p : puddles)
		dp[p[1]][p[0]] = -1;

	return RecursionCheck(n, m, n, m);
}