#include <string>
#include <vector>

using namespace std;


int solution(int n, int m, vector<int> section) {

	int answer = 0;
	int end_idx = 0;

	while (!section.empty())
	{
		if (end_idx <= (section.front() - 1))
		{
			end_idx = (section.front() - 1) + m;
			answer++;
		}
		else
		{
			section.erase(section.begin());
		}
	}
	return answer;
}