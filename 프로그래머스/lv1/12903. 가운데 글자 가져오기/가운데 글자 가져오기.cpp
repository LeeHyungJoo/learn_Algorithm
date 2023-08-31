#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int div = s.size() / 2;
    return s.size() & 1 ? s.substr(div,1) : s.substr(div-1,2);
}