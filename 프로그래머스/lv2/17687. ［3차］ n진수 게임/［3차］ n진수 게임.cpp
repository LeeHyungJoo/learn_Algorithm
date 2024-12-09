#include <string>
#include <vector>
#include <memory.h>

using namespace std;

string solution(int n, int t, int m, int p) {
	int caret = 0;
	int num = 0;
	int currentT = 0;
	int numStrSize = 0;
	char numStr[20];
	memset(numStr, 0, 20);

	string answer;
	while (t != currentT)
	{
		int currentNum = num;
		numStrSize = 0;

		while (true)
		{
			int remain = currentNum % n;
			currentNum = currentNum / n;

			char c;
			if (remain < 10)
				c = (char)(remain + 48);
			else
				c = 'A' + (char)(remain - 10);

			numStr[numStrSize++] = c;

			if (currentNum == 0)
				break;
		}

		for (int i = numStrSize - 1; i >= 0; i--)
		{
			if (caret % m == (p - 1))
			{
				answer.push_back(numStr[i]);
				currentT++;
			}

			if (t == currentT)
				break;

			caret++;
		}

		memset(numStr, 0, numStrSize);

		num++;
	}

	return answer;
}