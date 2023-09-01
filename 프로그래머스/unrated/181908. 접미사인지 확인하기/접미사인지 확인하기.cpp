#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
	int answer = 1;

	auto r_itr = is_suffix.rbegin();
	auto cmp_r_itr = my_string.rbegin();
	while (r_itr != is_suffix.rend())
	{
		if ((*r_itr) != (*cmp_r_itr))
		{
			answer = 0;
			break;
		}

		++r_itr; ++cmp_r_itr;
	}

	return answer;
}