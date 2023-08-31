#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
	int odd_sum = 0, even_sum = 0;
	for (int idx = 0; idx < num_list.size(); idx++)
	{
		if (idx & 1)
			odd_sum += num_list[idx];
		else
			even_sum += num_list[idx];
	}

	return odd_sum > even_sum ? odd_sum : even_sum;
}