#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    char k_ch = to_string(k)[0];
    while (i <= j)
    {
        string i_str = to_string(i);

        for (auto& ch : i_str)
        {
            if (ch == k_ch)
                answer++;
        }

        i++;
    }
    return answer;
}