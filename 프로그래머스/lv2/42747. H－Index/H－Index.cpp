#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	auto max = max_element(citations.begin(), citations.end());

	for (int ct = *max ; ct >= 0; --ct)
	{
		int h = 0;
		for (auto c : citations)
		{
			if (ct <= c)
				h++;
		}

		if (ct <= h) 
		{
			answer = ct;
			break;
		}
	}

	return answer;
}