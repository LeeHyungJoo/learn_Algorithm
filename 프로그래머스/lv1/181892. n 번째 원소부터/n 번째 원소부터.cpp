#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
	num_list.erase(num_list.begin(), num_list.begin() + n - 1);
	return num_list;
}