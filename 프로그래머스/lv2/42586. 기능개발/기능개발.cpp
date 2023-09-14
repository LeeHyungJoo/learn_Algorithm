#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        progresses[i] = 100 - progresses[i];
        progresses[i] = progresses[i] / speeds[i] + (progresses[i] % speeds[i] ? 1 : 0);
    }

    int last = -1;
    for (int i = 0; i < progresses.size(); i++)
    {
        if (last < progresses[i])
        {
            answer.push_back(1);
            last = progresses[i];
        }
        else
        {
            answer.back()++;
        }
    }

    return answer;
}