#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
	vector<int> answer;
	for (int num = 0; num < n; num++)
	{
		if ((num +1) % k == 0)
			answer.push_back((num + 1));
	}
	return answer;
}