#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	set<int> answer_set;

	int div = 2;
	while (n != 1)
	{
		if (n % div == 0)
		{
			n /= div;
			answer_set.insert(div);
		}
		else
		{
			div++;
		}
	}

	answer.assign(answer_set.begin(), answer_set.end());
	return answer;
}