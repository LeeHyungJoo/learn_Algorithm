#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() == 4 || s.size() == 6)
    {
            for (auto ch : s)
    {
        if (isdigit(ch) == false)
        {
            answer = false;
            break;
        }
    }
    }else
        answer = false;


    return answer;
}