#include <string>
#include <vector>
#include <numeric>

using namespace std;

long long memoi[100001];

long long pibo(long long n)
{
	if (n == 0 || n == 1)
		return memoi[n];

	if (memoi[n] < 0)
		memoi[n] = pibo(n - 1) + pibo(n - 2);

	return memoi[n] % 1234567;
}


int solution(int n) {
	fill(memoi, memoi + 100001, -1);
	memoi[0] = 0;
	memoi[1] = 1;
	return pibo(n);
}