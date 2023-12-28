#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
	num_list.erase(num_list.begin()+n, num_list.end());
	return num_list;
}