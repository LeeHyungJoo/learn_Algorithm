#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long solution(int n, vector<int> works) {
	long long answer = 0;

	while (true)
	{
		int max_work_count = 0;
		int next_max_value = 0;
		sort(works.begin(), works.end(), greater<int>());

		int max_value = works[0];
		if (max_value == 0 || n == 0)
		{
			break;
		}

		for (auto itr = works.begin(); itr != works.end(); ++itr)
		{
			if (*itr == max_value)
			{
				max_work_count++;
			}
			else
			{
				next_max_value = *itr;
				break;
			}
		}

		int gap = max_value - next_max_value;
		int remain_count = max_work_count;

		while (gap * max_work_count > n)
		{
			gap--;
		}

		if (n < remain_count)
		{
			remain_count = n;
			gap = 1;
		}


		for (int count = 0; count < remain_count; count++)
		{
			works[count] -= gap;
			n -= gap;
		}
	}

	for (auto work : works)
	{
		answer += work * work;
	}

	return answer;
}