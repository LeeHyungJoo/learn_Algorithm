#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
	bitset<20> bs(n);
	int count = bs.count();

	while (true)
	{
		bs = ++n;
		if (count == bs.count())
			break;
	}

	return n;
}