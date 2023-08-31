#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int num = left; num <= right; num++)
    {
        if( num == 1)
        {
            answer--;
            continue;
        }
        
        int sign = +1;
        for (int mul_num = 1; mul_num <= num / 2; mul_num++)
            if (num == mul_num * mul_num)
            {
                sign = -1;
                break;
            }
        answer += num * sign;
    }
    return answer;
}