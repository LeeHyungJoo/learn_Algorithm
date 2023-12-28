#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int c1_idx = 0, c2_idx = 0;

    for (const auto& g : goal)
    {
        if (c1_idx < cards1.size() && cards1[c1_idx] == g)
            c1_idx++;
        else if (c2_idx < cards2.size() && cards2[c2_idx] == g)
            c2_idx++;
        else
        {
            answer = "No";
            break;
        }
    }

    return answer;
}