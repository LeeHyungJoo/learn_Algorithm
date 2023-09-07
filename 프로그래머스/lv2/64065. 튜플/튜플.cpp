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

vector<int> solution(string s) {
    vector<int> answer;
    
    s.erase(s.begin());
    s.back() = '{';

    map<int, vector<int>> checks;
    int last_idx = 1;
    while (true)
    {
        auto idx = s.find('{', last_idx);
        if (idx == s.npos)
            break;

        vector<int> t;
        string temp;
        for (int i = last_idx; i < idx; i++)
        {
            if (!isdigit(s[i]) && !temp.empty())
            {
                t.push_back(atoi(temp.c_str()));
                temp.clear();
                continue;
            }

            temp.push_back(s[i]);
        }

        checks[t.size()] = t;
        last_idx = idx + 1;
    }

    answer.resize(checks.rbegin()->first);

    unordered_set<int> duplicated_check;
    int idx_a = 0;
    for (auto check : checks)
    {
        for (auto num : check.second)
        {
            if (duplicated_check.insert(num).second)
            {
                answer[idx_a] = num;
                break;
            }
        }
        idx_a++;
    }

    return answer;
}
