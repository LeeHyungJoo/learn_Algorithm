#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
	int sum = accumulate(num_list.begin(), num_list.end(), 0);
	int mul = 1; 
	for (auto num : num_list) mul *= num;
	return mul < sum * sum ? 1 : 0;
}