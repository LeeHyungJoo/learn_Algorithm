#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
	int answer = -1;
	for(int idx = 0 ; idx < num_list.size() ; ++idx)
		if (num_list[idx] < 0)
		{
			answer = idx;
			break;
		}
	return answer;
}