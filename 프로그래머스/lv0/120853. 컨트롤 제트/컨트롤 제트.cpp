#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string unit;
    string::iterator itr = s.begin();
    int old_num = 0;
    while (itr != s.end())
    {
        if ((*itr) == ' ')
        {
            if (unit == "Z")
            {
                answer -= old_num;
            }
            else
            {
                old_num = atoi(unit.c_str());
                answer += old_num;
            }

            unit.clear();
        }
        else
        {
            unit.push_back(*itr);
        }
        itr++;
    }

    if (!unit.empty())
    {
        if (unit == "Z")
        {
            answer -= old_num;
        }
        else
        {
            old_num = atoi(unit.c_str());
            answer += old_num;
        }
    }
    return answer;
}