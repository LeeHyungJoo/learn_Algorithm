#include <string>
#include <vector>

using namespace std;

void DFS(const vector<int>& numbers, int depth, int ret , int target, int& answer)
{
	if (depth == numbers.size())
	{
		if (ret == target) ++answer;
		return;
	}

	DFS(numbers, depth + 1, ret + numbers[depth], target, answer);
	DFS(numbers, depth + 1, ret - numbers[depth], target, answer);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	DFS(numbers, 0, 0, target, answer);

	return answer;
}