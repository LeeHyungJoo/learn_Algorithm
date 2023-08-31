#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.resize(2, 0);

    while (s.size() > 1)
    {
        int rem_count = 0;
        for (auto c : s)
            if (c == '0') rem_count++;

        answer[1] += rem_count;
        answer[0] ++;


        int length = s.size() - rem_count;
        s.clear();
        while (length != 0)
        {
            s.append(to_string(length % 2));
            length >>= 1;
        }
        reverse(s.begin(), s.end());
    }
    return answer;
}