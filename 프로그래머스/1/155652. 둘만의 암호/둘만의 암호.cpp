#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
	string answer = "";
	answer.resize(s.size());
	
	string alpha_seq;
	for (auto c = 'a'; c <= 'z'; c++)
	{
		if (skip.find(c) != skip.npos)
			continue;

		alpha_seq.push_back(c);
	}

	for (int i = 0; i < s.size(); i++)
		answer[i] = alpha_seq[(alpha_seq.find(s[i]) + index) % alpha_seq.size()];

	return answer;
}