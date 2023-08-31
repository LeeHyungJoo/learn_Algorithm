#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = *max_element(arr.begin(), arr.end());

    while (true)
    {
        bool check = true;
        for (auto elem : arr) 
        {
            if (answer % elem != 0)
            {
                check = false;
                break;
            }
        }

        if (check) break;
        answer++;
    }
    
    return answer;
}