#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
	string answer = "";
	for (auto idx : index_list)
		answer.push_back(my_string[idx]);
	return answer;
}