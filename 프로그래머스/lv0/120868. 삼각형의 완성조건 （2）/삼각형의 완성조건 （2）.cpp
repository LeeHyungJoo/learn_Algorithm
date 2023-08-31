#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;

    int org_max_value = 0;
    int org_min_value = 0;

    if (sides[0] > sides[1])
    {
        org_max_value = sides[0];
        org_min_value = sides[1];
    }
    else
    {
        org_max_value = sides[1];
        org_min_value = sides[0];
    }

    int last_side = 1;
    while (true)
    {
        if (org_max_value > last_side)
        {
            if (org_max_value < last_side + org_min_value)
                answer++;
        }
        else
        {
            if (last_side < org_max_value + org_min_value)
                answer++;
            else
                break;
        }

        last_side++;
    }

    return answer;
}
