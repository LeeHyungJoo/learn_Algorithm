#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
	string str1, str2;
	for (auto num : num_list)
		if (num & 1) str1.append(to_string(num));
		else str2.append(to_string(num));
	return atoi(str1.c_str()) + atoi(str2.c_str());
}