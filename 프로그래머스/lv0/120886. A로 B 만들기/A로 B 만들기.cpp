#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string before, string after) {
    int answer = 1;

    unordered_map<char, int> check;
    for (char ch : before)
        check[ch]++;

    for (char ch : after)
    {
        if (--check[ch] < 0)
        {
            return 0;
        }
    }

    for (auto u : check)
    {
        if (u.second != 0)
            return 0;
    }

    return answer;
}