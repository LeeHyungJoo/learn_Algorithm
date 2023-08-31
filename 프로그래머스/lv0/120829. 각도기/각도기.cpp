#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;
    if(angle == 180)
        answer = 4;
    else if(angle == 90)
        answer = 2;
    else if(angle > 0)
    {
        if(angle < 90)
        {
            answer = 1;
        }
        else
        {
            answer = 3;
        }
    }
        
    return answer;
}