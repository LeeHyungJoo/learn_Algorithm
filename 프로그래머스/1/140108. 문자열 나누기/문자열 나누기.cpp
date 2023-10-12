#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;

	char x = s[0];
	int x_n = 0, nx_n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (x == s[i])
			x_n++;
		else
			nx_n++;

		if (x_n == nx_n)
		{
			answer++;
			
			if (i + 1 == s.size())
				break;

			x_n = 0, nx_n = 0;
			x = s[i + 1];
		}
	}

	if (x_n != nx_n)
		answer++;

	return answer;
}