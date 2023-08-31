#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
   int max_idx = 0;
    int max_value = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        int num = numbers[i];
        if (max_value < num)
        {
            max_idx = i;
            max_value = num;
        }
    }

    int second_max_value = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (max_idx == i)
            continue;

        int num = numbers[i];
        if (second_max_value < num)
        {
            second_max_value = num;
        }
    }
    

    return max_value * second_max_value;
}