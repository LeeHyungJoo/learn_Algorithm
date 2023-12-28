#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	for (auto& unit : arr)
	{
		if (unit & 1)
		{
			if (unit < 50) unit <<= 1;
		}
		else
		{
			if (unit >= 50)unit >>= 1;
		}
	}
	return arr;
}