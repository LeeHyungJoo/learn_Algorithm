#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    for (int i = 0; i < static_cast<int>(num_list.size() / 2); i++)
    {
        int& swap = num_list[num_list.size() - 1 - i];
        int temp = num_list[i];
        num_list[i] = swap;
        swap = temp;

    }

    return num_list;
}