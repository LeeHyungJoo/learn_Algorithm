#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    int whole_count = n;
    int remain_count = 0;
    while (true)
    {
        int return_count = (whole_count / a) * b;
        if (return_count == 0)
            break;

        answer += return_count;
        remain_count = (whole_count % a);
        whole_count = remain_count + return_count;
    }

    return answer;
}