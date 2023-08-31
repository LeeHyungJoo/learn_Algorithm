#include <string>
#include <vector>
#include <map>

using namespace std;
int solution(vector<vector<int>> dots) {
    pair<int, int> max = make_pair(-256, -256);
    pair<int, int> min = make_pair(+256, +256);

    for (auto dot : dots)
    {
        if (dot[0] > max.first)
            max.first = dot[0];
        if (dot[1] > max.second)
            max.second = dot[1];

        if (dot[0] < min.first)
            min.first = dot[0];
        if (dot[1] < min.second)
            min.second = dot[1];
    }


    return (max.first - min.first) * (max.second - min.second);
}
