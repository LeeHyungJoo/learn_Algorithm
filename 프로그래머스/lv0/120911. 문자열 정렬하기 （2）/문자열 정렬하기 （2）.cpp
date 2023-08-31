#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    for (char& ch : my_string)
        ch = tolower(ch);
    sort(my_string.begin(), my_string.end());
    return my_string;
}