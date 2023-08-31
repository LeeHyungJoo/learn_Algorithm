#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    for (char c : to_string(x))
        sum += atoi(&c);
    return x % sum == 0;
}