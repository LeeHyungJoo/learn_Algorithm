#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int sideA[10001];
int sideB[10001];


int solution(vector<int> topping) 
{
	int cntA = 0, cntB = 0;

	for (auto t : topping)
	{
		if (sideB[t] == 0) cntB++;

		sideB[t]++;
	}

	int answer = 0;

	for (auto t : topping)
	{
		if (cntA == cntB) answer++;
		if (sideA[t] == 0) cntA++;

		sideA[t]++;
		sideB[t]--;

		if (sideB[t] == 0) cntB--;
	}

	return answer;
}