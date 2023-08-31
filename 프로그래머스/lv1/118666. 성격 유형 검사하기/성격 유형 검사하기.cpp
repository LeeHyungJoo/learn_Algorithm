#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    // A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
    vector<string> types { "RT", "CF", "JM", "AN" };
    vector<int> scores { 0,0,0,0 };
    // RT , CF, JM , AN
    //처음 껀 - ,  뒤에껀 +
    // -3 -2 -1 0 1 2 3

    for (int idx = 0; idx < survey.size(); idx++)
    {
        int sign_value = 1;
        auto type_itr = find(types.begin(), types.end(), survey[idx]);
        if (type_itr == types.end())
        {
            sign_value = -1;
            string str = survey[idx];
            rotate(str.begin(), str.begin() + str.size() - 1, str.end());
            type_itr = find(types.begin(), types.end(), str);
        }

        int gap = type_itr - types.begin();
        int score = ((choices[idx] - 4) * sign_value);
        scores[gap] += score;
    }


    for (int i = 0 ; i < scores.size(); i++)
    {
        if (scores[i] <= 0)
        {
            answer.push_back(types[i][0]);
        }
        else
        {
            answer.push_back(types[i][1]);
        }
    }

    return answer;
}