#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {

	multiset<int> sortedSet;

	for (auto operation : operations)
	{
		auto cmd = operation[0];
		if (cmd == 'I')
		{
			auto num = atoi(operation.substr(2).c_str());
			sortedSet.insert(num);
		}
		else if (cmd == 'D')
		{
			if (sortedSet.empty())
			{
				continue;
			}
			
			auto itr = operation.find('-');
			if (itr != string::npos)
			{
				sortedSet.erase(sortedSet.begin());
			}
			else
			{
				sortedSet.erase(--sortedSet.end());
			}
		}
	}

	vector<int> answer;
	if (sortedSet.empty())
	{
		answer.insert(answer.begin(), { 0,0 });
	}
	else
	{
		answer.insert(answer.begin(), { *--sortedSet.end(),  *sortedSet.begin() });
	}
	return answer;
}