#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    for(vector<int>::iterator itr = numlist.begin()
        ; itr != numlist.end()
        ;)
    {
        if(*itr % n != 0)
        {
            itr = numlist.erase(itr);    
        }
        else
        {
            itr++;
        }
    }
    return numlist;
}