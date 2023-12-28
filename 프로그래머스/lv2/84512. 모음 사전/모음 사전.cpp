#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> checks;
char dict[5] = {'A','E','I','O','U' };


void Recursion(string word)
{
    if (6 == word.size())
    {
        return;
    }

    checks.insert(word);
    for (int i = 0; i < 5; i++)
    {
        Recursion(word + dict[i]);
    }
}

int solution(string word) {
    int answer = 0;

    for (int i = 0; i < 5; i++)
    {
        string s(1, dict[i]);
        Recursion(s);
    }

    return distance(checks.begin(), checks.find(word)) + 1;
}