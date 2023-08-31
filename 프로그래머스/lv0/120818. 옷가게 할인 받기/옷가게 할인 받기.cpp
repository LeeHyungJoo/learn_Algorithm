#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    float discount = 0;
    
    switch (price / 100000)
    {
    case 0:
        break;
    case 1:
    case 2:
        discount = price * 0.05f;
        break;
    case 3:
    case 4:
        discount = price * 0.1f;
        break;
    default:
        discount = price * 0.2f;
        break;
    }
    return static_cast<int>(price - discount);
}