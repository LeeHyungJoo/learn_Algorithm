#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";

    for (auto& str : str_list)
        if (str.find(ex) == string::npos)
            answer.append(str);

    return answer;
}