#include <string>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	stack<int> mainStk;
	stack<int> subStk;

	int idx = order.size();
	for (int o : order)
		mainStk.push(idx--);

	bool failed = false;
	for (int i = 0; i < order.size(); i++)
	{
		int target = order[i];
		while (true)
		{
			if (!mainStk.empty() && mainStk.top() == target)
			{
				mainStk.pop();
				answer++;
				break;
			}
			else if(!subStk.empty() && subStk.top() == target)
			{
				subStk.pop();
				answer++;
				break;
			}
			else if(!mainStk.empty())
			{
				subStk.push(mainStk.top());
				mainStk.pop();
			}
			else
			{
				failed = true;
				break;
			}
		}
		if (failed)
			break;
	}

	return answer;
}