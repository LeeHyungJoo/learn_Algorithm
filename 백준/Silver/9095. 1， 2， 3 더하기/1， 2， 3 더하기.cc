#include <iostream>
#include <queue>

using namespace std;

int T;
int answer;
void RecursionSolution(int target, int current_sum)
{
	if (current_sum > target)
		return;

	if (target == current_sum)
	{
		answer++;

		return;
	}


	RecursionSolution(target, current_sum + 1);
	RecursionSolution(target, current_sum + 2);
	RecursionSolution(target, current_sum + 3);
}

int main()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int target;
		cin >> target;

		RecursionSolution(target, 0);
		cout << answer << endl;
		answer = 0;
	}


	return 0;
}