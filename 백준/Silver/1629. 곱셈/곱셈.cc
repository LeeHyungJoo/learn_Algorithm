#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>

#include <iostream>
using namespace std;

long long num, divide_factor;

long long  solution(long long count)
{
	if (count == 1)
	{
		return  num % divide_factor;
	}

	long long result = solution(count / 2);

	result = (result * result) % divide_factor;
	if (count % 2)
	{
		result = (result * num) % divide_factor;
	}

	return result;
}

int main()
{
	long long count = 0;

	cin >> num >> count >> divide_factor;

	cout << solution(count);
	return 0;
}