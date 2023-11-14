#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;


	unordered_map<string, int> want_count;
	for (int i = 0; i < want.size(); i++)
	{
		want_count[want[i]] = number[i];
	}

	vector<unordered_map<string, int>> part_sum(discount.size() + 1);
	part_sum[0][discount[0]] = 0;

	for (int i = 0; i < discount.size() ; i++)
	{
		part_sum[i + 1][discount[i]] = 1;

		for (auto pre : part_sum[i])
		{
			part_sum[i  + 1][pre.first] += pre.second;
		}
	}

	for (int i = 0; i <= discount.size() - 10; i++)
	{
		bool check = true;
		for (auto w : want_count)
		{
			if (w.second != part_sum[i + 10][w.first] - part_sum[i][w.first])
			{
				check = false;
				break;
			}
		}

		if (check)
		{
			answer ++;
		}
	}

	return answer;
}