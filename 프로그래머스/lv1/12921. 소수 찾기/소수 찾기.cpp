#include <string>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

int solution(int n) {
     int answer = 0;

    vector<bool> primes;
    primes.resize(n - 1, true);
    // n== 3 -> 2,3 

    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i - 2])
            for (int j = i * i; j <= n; j += i)
                primes[j - 2] = false;
    }
    for (auto prime : primes)
        if (prime == true)
            answer++;

    return answer;
}