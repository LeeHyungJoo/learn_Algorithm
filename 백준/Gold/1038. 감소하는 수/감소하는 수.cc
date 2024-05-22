#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <numeric>
#include <string>
#include <map>

using namespace std;

int N;
constexpr int LIMITS = 1000000;

int main()
{
	cin >> N;
	if (N == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	
	map<int, map<int, vector<string>>> checks;
	for (int numLength = 1; numLength <= 10; numLength++)
	{
		for (int firstNum = numLength - 1; firstNum < 10; firstNum++)
		{
			auto nl_itr = checks.find(numLength - 1);
			if (nl_itr != checks.end())
			{
				auto firstNumStr = to_string(firstNum);
				for (int nextFirstNum = 0; nextFirstNum < firstNum; nextFirstNum++)
				{
					auto nextFirstNumStr = to_string(nextFirstNum);
					auto nf_itr = nl_itr->second.find(nextFirstNum);
					if (nf_itr == nl_itr->second.end())
						continue;

					for (const auto& nextNumStr : nf_itr->second)
					{
						checks[numLength][firstNum].push_back(firstNumStr + nextNumStr);
					}
				}
			}
			else
			{
				checks[numLength][firstNum].push_back(to_string(firstNum));
			}
		}
	}

	int n = 0;
	for (const auto& nl : checks)
		for (const auto& fn : nl.second)
			for (const auto& numStr : fn.second)
			{
				if (n == N)
				{
					cout << numStr << endl;
					return 0;
				}
				n++;
			}

	cout << -1 << endl;
	return 0;
}