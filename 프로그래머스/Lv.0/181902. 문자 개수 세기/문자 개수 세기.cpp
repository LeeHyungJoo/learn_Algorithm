#include <string>
#include <vector>

using namespace std;


vector<int> solution(string my_string) {
	vector<int> answer(52, 0);
	for (auto c : my_string)
	{
		if (isupper(c))
			answer[c - 65]++;
		else
			answer[c - 71]++;
	}
	return answer;
}