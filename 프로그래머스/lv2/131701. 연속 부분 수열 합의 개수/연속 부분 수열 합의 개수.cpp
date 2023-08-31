#include <string>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int solution(vector<int> elements) {
	set<int> sum_check;

	int origin_size = elements.size();
	elements.insert(elements.end(), elements.begin(), elements.end());

	vector<int>sums(origin_size * 2 + 1);
	sums[0] = 0;
	for (int idx = 0; idx < elements.size();idx++)
		sums[idx + 1] = sums[idx] + elements[idx];

	for (int section = 1; section <= origin_size; section++)
		for (int idx = 0; idx < origin_size; idx ++)
			sum_check.insert(sums[idx + section] - sums[idx]);

	return sum_check.size();
}