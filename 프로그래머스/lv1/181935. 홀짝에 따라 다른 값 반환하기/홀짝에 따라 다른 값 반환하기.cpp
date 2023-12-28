#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
    
	if (n & 1)
	{
		for (int i = 0; i < n; i += 2)
			answer += (i + 1);
	}
	else
	{
		for (int i = 1; i < n; i += 2)
			answer += (i + 1) * (i + 1);
	}

	return answer;
}