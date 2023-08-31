#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    
    for (int i = 0; i < static_cast<int>(my_string.size() / 2); i++)
    {
        char& swap = my_string[my_string.size() - 1 - i];
        char temp = my_string[i];
        my_string[i] = swap;
        swap = temp;

    }
    return my_string;
}