#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> numbers) {
    double answer = accumulate(numbers.begin(), numbers.end(),0) / (double)numbers.size();
    int temp = answer * 10;

    int last = temp % 10;
    if (last == 0 || last == 5)
    {
        answer = (double)temp / 10;
    }
    else
    {
        answer = (int)answer;
    }
    return answer;
}