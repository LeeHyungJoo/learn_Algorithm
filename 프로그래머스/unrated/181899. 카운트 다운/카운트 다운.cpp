#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start, int end_num) {
    vector<int> answer;
    if(start < end_num)
    {
        for(int i = start ; i <= end_num ; i++)
            answer.push_back(i);
    }
    else
    {
        for(int i = start ; i >= end_num ; i--)
            answer.push_back(i);
    }
    return answer;
}