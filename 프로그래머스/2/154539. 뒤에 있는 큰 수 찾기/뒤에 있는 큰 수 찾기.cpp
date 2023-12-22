#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> stk;

    for (int i = numbers.size() - 1; i > -1; i--)
    {
        if (stk.empty()) 
        {
            stk.push(numbers[i]);
            answer.push_back(-1);
        }
        else
        {
            int next = -1;
            while (!stk.empty())
            {
                auto cur = stk.top();
                if (cur <= numbers[i])
                {
                    stk.pop();
                }
                else
                {
                    answer.push_back(cur);
                    break;
                }
            }

            if (stk.empty())
            {
                answer.push_back(-1);
            }

            stk.push(numbers[i]);
        }
    }   

    reverse(answer.begin(), answer.end());
    return answer;
}