#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    auto itr = answer.begin();
    for (auto a : arr)
    {
        itr = answer.insert(itr, a, a);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}