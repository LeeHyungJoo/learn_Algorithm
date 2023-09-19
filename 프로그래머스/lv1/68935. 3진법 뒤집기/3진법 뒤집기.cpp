#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n) {
	int answer = 0;

	stack<int> t;
	while (n != 0)
	{
		t.push(n%3);
		n /= 3;
	}
	
	int tri = 1;
	while (!t.empty())
	{
		answer += tri * t.top();
		t.pop();
		tri *= 3;
	}

	return answer;
}