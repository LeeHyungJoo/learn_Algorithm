#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<int, int, greater<int>> flip_map(const map<int, int>& src)
{
    map<int, int, greater<int>> dst;
    transform(src.begin(), src.end(), inserter(dst, dst.begin()), [&](const pair<int, int>& p) {return pair<int, int>(p.second, p.first); });
    return dst;
}

vector<int> solution(string s) {
    map<int, int>checks;
    string int_str;
    for (auto c : s)
    {
        if (isdigit(c))
        {
            int_str.push_back(c);
        }
        else if(!int_str.empty())
        {
            checks[atoi(int_str.c_str())]++;
            int_str.clear();
        }
    }

    vector<int> answer(checks.size());
    int idx = 0;

    for (auto item : flip_map(checks))
        answer[idx++] = item.second;

    return answer;
}