#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>
#include <regex>
#include <iostream>
#include <list>

using namespace std;

int M;
char cmd[11];

int main()
{
	cin >> M;

	int bitmask = 0;
	vector<int>results;
	int val;

	for (int m = 0; m < M; m++)
	{
		scanf(" %s %d", &cmd, &val);

		if (cmd[0] == 'a' && cmd[1] == 'l')
		{
			bitmask = (1 << 21) - 1;
		}
		else if(cmd[0] == 'e')
		{
			bitmask = 0;
		}
		else
		{
			if (cmd[0] == 'a')
				bitmask |= (1 << val);
			else if (cmd[0] == 'r')
				bitmask &= ~(1 << val);
			else if (cmd[0] == 't')
				bitmask ^= (1 << val);
			else if (cmd[0] == 'c')
				printf("%d\n", (bitmask & (1 << val)) == 0 ? 0 : 1);
		}
	}
		
	return 0;
}