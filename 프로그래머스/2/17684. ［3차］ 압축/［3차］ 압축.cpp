#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    int lastIdx = 1;
    unordered_map<string, int> dict;
    for (char alpha = 'A'; alpha <= 'Z'; alpha++)
        dict[string(1, alpha)] = lastIdx++;

    for (int idx = 0; idx < msg.size();)
    {
        string word(1, msg[idx]);
        auto currentItr = dict.find(word);

        while (true)
        {
            if (idx + 1 == msg.size())
            {
                idx++;
                answer.push_back(currentItr->second);
                break;
            }

            word += msg[++idx];
            auto nextItr = dict.find(word);
            if (nextItr == dict.end())
            {
                dict[word] = lastIdx++;
                answer.push_back(currentItr->second);
                break;
            }
            else 
            {
                currentItr = nextItr;
            }
        }
        
    }


    return answer;
}
