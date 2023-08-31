#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;

    string unit;
    for (auto ch : my_string)
    {
        if (!isdigit(ch))
        {
            answer += atoi(unit.c_str());
            unit.clear();
        }
        else
        {
            unit.push_back(ch);
        }
    }

    if(!unit.empty())
        answer += atoi(unit.c_str());

    return answer;
}