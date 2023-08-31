#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    answer.resize(n);

    for (int i = 0; i < n; i++)
    {
        int map_1 = arr1[i];
        int map_2 = arr2[i];

        string row;
        row.insert(0, n,' ');

        for (int j = 0; j < n; j++, map_1 >>= 1)
        {
            if (map_1 == 0)
                break;

            int wall_1 = map_1 % 2;
            if (wall_1 == 1)
                row[n - j - 1] = '#';
        }

        for (int j = 0; j < n; j++, map_2 >>= 1)
        {
            if (row[n - j - 1] == '#')
                continue;

            if (map_2 == 0)
                break;

            int wall_2 = map_2 % 2;
            if (wall_2 == 1)
                row[n - j - 1] = '#';
        }
        answer[i] = row;
    }


    return answer;
}