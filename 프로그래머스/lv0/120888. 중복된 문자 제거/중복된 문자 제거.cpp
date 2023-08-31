#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string my_string) {
    set<char> check;

    for (string::iterator itr = my_string.begin(); itr != my_string.end();)
    {
        if (check.insert(*itr).second == true)
        {
            itr++;
        }
        else
        {
            itr = my_string.erase(itr);
        }
    }

    return my_string;
}