#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if (direction == "right")
    {
        int temp = *numbers.rbegin();
        for (vector<int>::reverse_iterator itr = numbers.rbegin(); itr != numbers.rend();itr++)
        {
            if (itr + 1 != numbers.rend())
            {
                *itr = *(itr + 1);
            }
            else
            {
                *itr = temp;
            }
        }
    }
    else if(direction == "left")
    {
        int temp = *numbers.begin();
        for (vector<int>::iterator itr = numbers.begin(); itr != numbers.end();itr++)
        {
            if (itr + 1 != numbers.end())
            {
                *itr = *(itr + 1);
            }
            else
            {
                *itr = temp;
            }
        }
    }

    return numbers;
}