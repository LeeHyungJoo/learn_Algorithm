#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<stack<int>> checks;
    for (auto elem : ingredient)
    {
        if (checks.empty())
        {
            if (elem == 1)
            {
                stack<int> new_stack;
                new_stack.push(elem);
                checks.push(new_stack);
            }
            continue;
        }

        if (elem == 1)
        {
            bool answer_check = true;
            if (checks.top().size() == 3)
            {
                int check_val = 3;
                while (check_val != 0)
                {
                    if (checks.top().empty())
                    {
                        answer_check = false;
                        break;
                    }

                    if (checks.top().top() == check_val)
                    {
                        checks.top().pop();
                    }
                    else
                    {
                        answer_check = false;
                        break;
                    }

                    check_val--;
                }
            }
            else
            {
                answer_check = false;
            }


            if (answer_check)
            {
                checks.pop();
                answer++;
            }
            else
            {
                stack<int> new_stack;
                new_stack.push(elem);
                checks.push(new_stack);
            }
        }
        else
        {
            checks.top().push(elem);
        }
    }

    return answer;
}