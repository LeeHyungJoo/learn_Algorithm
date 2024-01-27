#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;

    size_t caret = 0;
    while (true)
    {
        caret = myString.find(pat, caret);
        if (caret == string::npos)
            break;
        caret++;
        answer++;
    }

    return answer;
}
