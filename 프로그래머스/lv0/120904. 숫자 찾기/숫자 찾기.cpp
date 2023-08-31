#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    string str = to_string(num);
    char k_str = to_string(k)[0];
	for (int i = 0; i < str.size(); i++)
    {
        if (k_str == str[i])
        {
            answer = i + 1;
            break;
        }
    }
    return answer;
}