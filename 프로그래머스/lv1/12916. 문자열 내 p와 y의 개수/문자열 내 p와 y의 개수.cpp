#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num = 0;

    for (char ch : s)
    {
        switch (ch)
        {
        case 'p':
        case 'P':
            num++;
            break;
        case 'y':
        case 'Y':
            num--;
            break;
        }
    }

    return num == 0;
}