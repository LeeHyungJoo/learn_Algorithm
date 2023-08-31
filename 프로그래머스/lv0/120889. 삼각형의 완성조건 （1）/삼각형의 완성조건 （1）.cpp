#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    
    int max_idx = 0;
    int max = 0;
    for(int i = 0 ; i < sides.size(); i++)
    {
        int side = sides[i];
        if(max < side)
        {
            max_idx = i;
            max = side;
        }
    }
    
    int remain = 0;
    for(int i = 0 ; i < sides.size(); i++)
    {
        if(i == max_idx)
            continue;
        remain += sides[i];
    }
    
    
    return max < remain ? 1 : 2;
}