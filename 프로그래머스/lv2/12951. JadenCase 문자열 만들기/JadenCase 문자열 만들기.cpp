#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool bJaden = true;
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        if ((*itr) == ' ')
        {
            bJaden = true;
        }
        else
        {
            if (bJaden == true)
            {
                if (!isdigit(*itr))
                {
                    *itr = toupper(*itr);
                }
                bJaden = false;
            }
            else
            {
                *itr = tolower(*itr);
            }
        }
    }

    return s;
}