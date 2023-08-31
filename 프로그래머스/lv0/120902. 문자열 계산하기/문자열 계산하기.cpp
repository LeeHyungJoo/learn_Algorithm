#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int lVal = 0;
    int rVal = 0;
    bool bPlus = false;
    string unit;
    for (auto ch : my_string)
    {
        if (ch == '+')
        {
            bPlus = true;
        }
        else if (ch == '-')
        {
            bPlus = false;
        }
        else if (isdigit(ch))
        {
            unit.push_back(ch);
        }
        else
        {
            if (rVal == 0)
            {
                rVal = atoi(unit.c_str());
            }
            else
            {
                lVal = atoi(unit.c_str());

                //Flush
                if (bPlus)
                    rVal += lVal;
                else
                    rVal -= lVal;
                lVal = 0;
            }
            unit.clear();
        }
    }

    if (!unit.empty())
    {
        lVal = atoi(unit.c_str());

        //Flush
        if (bPlus)
            rVal += lVal;
        else
            rVal -= lVal;
    }

    return rVal;
}