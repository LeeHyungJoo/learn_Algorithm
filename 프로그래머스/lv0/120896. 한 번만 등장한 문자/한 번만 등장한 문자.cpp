#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";

    map<char, int> checks;
    for (char ch : s)
        checks[ch]++;

    for (auto check : checks)
        if (check.second == 1)
            answer.push_back(check.first);
    
    return answer;
}