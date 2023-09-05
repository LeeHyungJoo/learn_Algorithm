#include <string>
#include <vector>

using namespace std;


long long memoi[2001];


long long recursion(int n)
{
    if (n == 1 || n == 2)
        return memoi[n];

    if (memoi[n] == 0)
        memoi[n] = recursion(n - 1) + recursion(n - 2) % 1234567;

    return memoi[n]  % 1234567;
}

long long solution(int n) 
{
    fill(memoi, memoi + 2001, 0);
    memoi[1] = 1;
    memoi[2] = 2;

    return recursion(n);
}
