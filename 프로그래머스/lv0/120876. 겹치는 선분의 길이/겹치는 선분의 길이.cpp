#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;

    int min_bound = (numeric_limits<int>::max)();
    int max_bound = (numeric_limits<int>::min)();

    for (vector<int>& line : lines)
    {
        for (int integer : line)
        {
            if (min_bound > integer)
                min_bound = integer;

            if (max_bound < integer)
                max_bound = integer;
        }
    }

    for (float i = min_bound - 0.5f; i <= max_bound; i += 1.0f)
    {
        int duplicated_level = 0;
        for (auto& line : lines)
        {
            if (line[0] < i && i < line[1])
                duplicated_level++;

            if (duplicated_level > 1)
            {
                answer++;
                break;
            }
        }
    }


    return answer;
}