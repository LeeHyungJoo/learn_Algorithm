#include <stack>
#include <iostream>

using namespace std;

int num_list[1000000];
int answer[1000000];

int main()
{
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) cin >> num_list[n];

	stack<int> stk;
	for (int n = N - 1; n >= 0 ; --n)
	{
		while (!stk.empty() && stk.top() <= num_list[n]) stk.pop();

		answer[n] = stk.empty() ? -1 : stk.top();
		stk.push(num_list[n]);
	}

	for (int n = 0; n < N; n++) cout << answer[n] << " ";

	return 0;
}