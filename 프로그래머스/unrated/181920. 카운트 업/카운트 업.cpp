#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
	vector<int> answer;
	for (int n = start_num; n <= end_num; n++)
		answer.push_back(n);
	return answer;
}