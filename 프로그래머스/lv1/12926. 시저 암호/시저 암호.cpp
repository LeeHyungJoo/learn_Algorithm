#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {

	char f, l;
	for (auto& c : s)
	{
		if (!isalpha(c))
			continue;

		if (islower(c))
		{
			f = 'a';
			l = 'z';
		}
		else
		{
			f = 'A';
			l = 'Z';
		}

		int c_i = c + n;
		if (c_i > l) c_i = f + c_i - l -1;
		c = c_i;
	}

	return s;
}