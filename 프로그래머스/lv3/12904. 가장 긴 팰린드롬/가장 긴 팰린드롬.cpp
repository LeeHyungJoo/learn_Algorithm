#include <iostream>
#include <string>
#include <stack>
using namespace std;

void TwoPointerSearch(const string& s, int left, int right, int len, int& max)
{
	if (left < 0 || right > s.size() - 1)
		return;

	if (s[left] == s[right])
	{
		len += 2;
		if (max < len)
			max = len;
	}
	else
		return;

	TwoPointerSearch(s, --left, ++right, len, max);
}

int solution(string s)
{
	int answer = 1;

	for (int i = 1; i < s.size(); i++)
	{
		TwoPointerSearch(s, i - 1, i, 0, answer);
		TwoPointerSearch(s, i - 1, i + 1, 1, answer);
	}

	return answer;
}
