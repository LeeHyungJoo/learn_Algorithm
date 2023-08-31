#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int service_drink_count = n / 10;
    return n * 12000 + (k-service_drink_count) * 2000;
}