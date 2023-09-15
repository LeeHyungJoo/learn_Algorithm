#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> num_list(N), answers(N);
	for (int n = 0; n < N; n++)
		cin >> num_list[n];

	stack<int> stk;
	reverse(num_list.begin(), num_list.end());
	for (int n = 0; n < N; n++)
	{
		while (!stk.empty() && stk.top() <= num_list[n])
			stk.pop();

		answers[n] = stk.empty() ? -1 : stk.top();
		stk.push(num_list[n]);
	}
	
	reverse(answers.begin(), answers.end());
	for (auto answer : answers)
		cout << answer << " ";

	return 0;
}