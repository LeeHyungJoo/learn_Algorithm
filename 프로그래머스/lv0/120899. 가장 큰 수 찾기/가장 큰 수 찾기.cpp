#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    answer.resize(2,0);
    int max = numeric_limits<int>::min();
    int idx = 0;
    for(int i = 0 ; i < array.size() ; i++)
    {
        if(max < array[i])
        {
            max = array[i];
            idx = i;
        }
    }
    answer[0] = max;
    answer[1] = idx;
    return answer;
}