#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    
    int count = my_str.size() / n;
    for (int i = 0; i < count; i++)
        answer.push_back(my_str.substr(i * n, n));

    int remain = my_str.size() % n;
    if(remain != 0)
        answer.push_back(my_str.substr(my_str.size() - remain, remain));

    return answer;
}