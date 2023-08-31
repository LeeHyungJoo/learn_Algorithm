#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int word_idx = 0;
    for (char& ch : s)
    {
        if (ch == ' ')
        {
            word_idx = 0;
            continue;
        }

        if (word_idx % 2 == 0)
        {
            if (islower(ch))
                ch = toupper(ch);
        }
        else
        {
            if (isupper(ch))
                ch = tolower(ch);
        }
        word_idx++;
    }

    return s;
}