#include <string>
#include <vector>

using namespace std;

bool CurseThree(int& num)
{
    if (num % 3 == 0)
    {
        num++;
        return true;
    }
    else
    {
        auto str = to_string(num);
        if (str.find('3') != string::npos)
        {
            num++;
            return true;
        }
    }

    return false;
}

int solution(int n) {
    int cursed_num = 0;

    for (int i = 0; i < n; i++)
    {
        cursed_num++;
        while (CurseThree(cursed_num)){}
    }

    return cursed_num;
}