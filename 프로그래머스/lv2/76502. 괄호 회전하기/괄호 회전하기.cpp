#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>

#include <iostream>
using namespace std;
unordered_map<char, char> indices;

int solution(string s) {
    int answer = 0;

     indices[']'] = '[';
     indices['}'] = '{';
     indices[')'] = '(';

    int max_trial = s.size();
    s.append(s);
    for (int trial = 0; trial < max_trial; trial++)
    {
        stack<char> stacks;
         for (int idx = trial; idx < trial + max_trial; idx++)
        {
            auto itr = indices.find(s[idx]);
            if (itr == indices.end())
            {
                stacks.push(s[idx]);
            }
            else
            {
                if (stacks.empty())
                {
                    stacks.push('-');
                    break;
                }

                if (stacks.top() == itr->second)
                {
                    stacks.pop();
                }
            }
        }

        if (stacks.empty())
            answer++;
    }

    return answer;
}
