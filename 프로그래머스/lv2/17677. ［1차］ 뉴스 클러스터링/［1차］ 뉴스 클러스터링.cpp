#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>
#include <regex>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    for (auto& c : str1)
        if (isupper(c))
            c = tolower(c);

    for (auto& c : str2)
        if (isupper(c))
            c = tolower(c);
    
    unordered_map<string, int> check1, check2;
    set<string> checks;
    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            auto t = str1.substr(i, 2);
            checks.insert(t);
            check1[t]++;
        }
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            auto t = str2.substr(i, 2);
            checks.insert(t);
            check2[t]++;
        }
    }
    
    if (checks.empty())
        return 65536;
    
    double jaccard = 0.0;
    int n = 0, dn = 0;
    for (const auto& s : check1)
    {
        auto itr = check2.find(s.first);
        if (itr != check2.end())
            n += min(s.second, itr->second);
    }

    for (const auto& c : checks)
    {
        auto itr1 = check1.find(c);
        auto itr2 = check2.find(c);

        if (itr1 != check1.end() && itr2 != check2.end())
        {
            dn += max(itr1->second, itr2->second);
        }
        else if (itr1 == check1.end() && itr2 != check2.end())
        {
            dn += itr2->second;
        }
        else if (itr1 != check1.end() && itr2 == check2.end())
        {
            dn += itr1->second;
        }
    }

    answer = ((double)n / dn) * 65536;
    return answer;
}
