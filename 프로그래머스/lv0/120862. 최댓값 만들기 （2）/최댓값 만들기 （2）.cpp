#include <string>
#include <vector>

using namespace std;
int solution(vector<int> numbers) {
    int max_value = numeric_limits<int>::min(); 
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int k = i + 1; k < numbers.size(); k++)
        {
            int max_candidate = numbers[i] * numbers[k];
            if (max_value < max_candidate)
                max_value = max_candidate;
        }
    }
    return max_value;
}