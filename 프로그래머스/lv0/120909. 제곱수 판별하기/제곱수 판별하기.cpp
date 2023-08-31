#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    for(int k = 1 ; k <= n / 2 ; k++)
    {
        if(n % k == 0 && n / k == k)
        {
            answer = 1;
            break;
        }
    }
    return answer;
}