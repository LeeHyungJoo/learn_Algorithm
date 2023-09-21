#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	unordered_map<char, int> indices;

	for (int idx = 0 ; idx < s.size() ; ++idx)
	{
		auto itr = indices.find(s[idx]);
		if (itr == indices.end())
			answer.push_back(-1);
		else
			answer.push_back(idx - itr->second);

		indices[s[idx]] = idx;
	}

	return answer;
}