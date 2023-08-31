#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;

	if (s < n)
	{
		answer.push_back(-1);
		return answer;
	}

	int remain = s % n;
	answer.resize(n, s / n);
	for (int rvs_idx = n - 1; remain != 0; rvs_idx--, remain--)
	{
		answer[rvs_idx] += 1;
	}

	return answer;
}