#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <chrono>

using namespace std;

struct CombinationInfo
{
	int r;
	int n;
	int* arr;
};

void searchRealDwarf(const CombinationInfo& combinationInfo, int start_idx , vector<int>& candidates)
{
	if (candidates.size() == combinationInfo.r)
	{
		int sum = 0;
		for (auto candidate : candidates)
		{
			sum += combinationInfo.arr[candidate];
		}

		if (sum == 100)
		{
			auto sorted_vec = vector<int>();
			sorted_vec.resize(7);
			int idx = 0;
			for (auto candidate : candidates)
			{
				sorted_vec[idx++] = combinationInfo.arr[candidate];
			}
			sort(sorted_vec.begin(), sorted_vec.end());

			for (auto val : sorted_vec)
				cout << val << endl;

			exit(0);
		}
	}

	for (int idx = start_idx; idx < combinationInfo.n; idx++)
	{
		candidates.push_back(idx);
		searchRealDwarf(combinationInfo, idx + 1, candidates);
		candidates.pop_back();
	}
}


int main()
{
	int arr[9];
	for (int i = 0; i < 9;i++)
	{
		cin >> arr[i];
	}

	CombinationInfo combinationInfo;
	combinationInfo.r = 7;
	combinationInfo.n = 9;
	combinationInfo.arr = arr;

	vector<int> init;
	searchRealDwarf(combinationInfo, 0, init);

	return 0;
}