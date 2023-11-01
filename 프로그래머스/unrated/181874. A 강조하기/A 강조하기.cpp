#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    for (auto& c : myString)
    {
        if(!isalpha(c) || c == 'A')
            continue;
        
        c = c == 'a' ? toupper(c) : tolower(c);
    }
    return myString;
}