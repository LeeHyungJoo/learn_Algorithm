#include <string>
#include <vector>

using namespace std;


int visited[201] = {};

void RecursiveCheck(const vector<vector<int>>& computers, int to)
{
	visited[to] = 1;

	for (int i = 0; i < computers[to].size();i++)
	{
		if (computers[to][i] == 0)
			continue;

		if (visited[i] == 1)
			continue;

		RecursiveCheck(computers, i);
	}
}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 1)
			continue;

		RecursiveCheck(computers, i);
		answer++;
	}

	return answer;
}
