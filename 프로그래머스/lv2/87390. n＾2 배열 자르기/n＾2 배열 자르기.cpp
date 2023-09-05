#include <string>
#include <vector>

using namespace std;
vector<int> solution(int n, long long left, long long right) {

    vector<int> answer(right - left + 1, 0);

    for (long long s = left; s <= right; s++)
    {
        long long y = s / n;
        long long x = s % n;
        answer[s - left] =  x> y ? x + 1 : y +1 ;
    }

    return answer;
}