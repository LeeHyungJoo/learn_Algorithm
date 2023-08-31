#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        int limit = 0;
        for (int k = 0; k <= i; k++)
        {
            if ((i + 1) % (k + 1) == 0)
                limit++;

            if (limit >= 3) 
            {
                answer++;
                break;
            }
        }
    }
    return answer;
}