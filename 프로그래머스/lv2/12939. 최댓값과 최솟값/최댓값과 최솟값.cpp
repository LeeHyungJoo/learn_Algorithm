#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int min = (numeric_limits<int>::max)();
    int max = (numeric_limits<int>::min)();

    int old_space_idx = 0;
    while (true)
    {
        int space_idx = s.find(' ', old_space_idx);
        if (space_idx < 0)
            space_idx = 0;

        string num_str = s.substr(old_space_idx, space_idx - old_space_idx);
        
        int num = atoi(num_str.c_str());
        if (min > num)
            min = num;
        if (max < num)
            max = num;

        if (space_idx == 0)
            break;

        old_space_idx = space_idx + 1;
    }

    return to_string(min).append(" ").append(to_string(max));
}