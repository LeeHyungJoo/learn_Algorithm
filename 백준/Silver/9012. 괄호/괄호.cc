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

using namespace std;



int  main()
{
	int count;
	cin >> count;

	while (count != 0)
	{
		int valid = 0;

		string parenthesis;
		cin >> parenthesis;

		bool bSuccess = true;
		for (int i = 0; i < parenthesis.size(); i++)
		{
			if (parenthesis[i] == '(')
				++valid;
			else
				--valid;

			if (valid < 0)
			{
				bSuccess = false;
				break;
			}
		}

		bSuccess &= valid == 0;

		cout << (bSuccess ? "YES" : "NO") << "\n";
		count--;
	}

	return 0;
}