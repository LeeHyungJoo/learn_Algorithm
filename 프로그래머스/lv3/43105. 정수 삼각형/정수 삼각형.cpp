#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;
int memoi[500][500];

int solution(vector<vector<int>> triangle)
{
	for (int idx = 0; idx < 500;idx++)
	{
		fill_n(memoi[idx], 500, -1);
	}
	memoi[0][0] = triangle[0][0];

	for (int y_idx = 1; y_idx < triangle.size(); y_idx++)
	{
		for (int x_idx = 0; x_idx < triangle[y_idx].size(); x_idx++)
		{
			int left_val = -1;
			if (x_idx - 1 >= 0)
			{
				left_val = memoi[y_idx - 1][x_idx - 1];
			}

			int right_val = memoi[y_idx - 1][x_idx];
			if (memoi[y_idx][x_idx] < 0)
			{
				memoi[y_idx][x_idx] = triangle[y_idx][x_idx] + (left_val > right_val ? left_val : right_val);
			}
		}
	}

	int biggest_num = 0;
	const auto& last_y_memoi = memoi[triangle.size()-1];
	for (int idx = 0; idx < triangle[triangle.size() - 1].size() ;idx++)
	{
		if (biggest_num < last_y_memoi[idx])
		{
			biggest_num = last_y_memoi[idx];
		}
	}

	return biggest_num;
}