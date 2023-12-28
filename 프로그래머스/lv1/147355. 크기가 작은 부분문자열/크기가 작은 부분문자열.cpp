#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
	int answer = 0;

	size_t size = p.size();
	for (int i = 0; i <= t.size() - size; i++)
	{
		if (t.substr(i, size) > p)
			continue;

		answer++;
	}

	return answer;
}