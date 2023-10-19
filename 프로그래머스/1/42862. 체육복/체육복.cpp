#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	for (auto r_itr = reserve.begin() ; r_itr != reserve.end();)
	{
		auto itr = find(lost.begin(), lost.end(), *r_itr);
		if (itr != lost.end())
		{
			lost.erase(itr);
			r_itr = reserve.erase(r_itr);
		}
		else
		{
			r_itr++;
		}
	}

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (auto l_itr = lost.begin(); l_itr != lost.end();)
	{
		auto f_r_itr = find(reserve.begin(), reserve.end(), (*l_itr) - 1);
		if (f_r_itr != reserve.end())
		{
			l_itr = lost.erase(l_itr);
			reserve.erase(f_r_itr);
		}
		else
		{
			auto b_r_itr = find(reserve.begin(), reserve.end(), (*l_itr) + 1);
			if (b_r_itr != reserve.end())
			{
				l_itr = lost.erase(l_itr);
				reserve.erase(b_r_itr);
			}
			else
			{
				l_itr++;
			}
		}
	}

	return n - lost.size();
}