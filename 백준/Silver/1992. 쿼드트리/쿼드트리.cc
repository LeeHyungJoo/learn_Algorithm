#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>
#include <regex>
#include <iostream>

using namespace std;


int n; 
string s;   
char a[65][65];
string quard(int y, int x, int size){
    if(size == 1) return string(1, a[y][x]); 
    char b = a[y][x]; 
    string ret = "";  
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){ 
            if(b != a[i][j]){ 
                ret += '(';
                ret += quard(y, x, size / 2); 
                ret += quard(y, x + size / 2, size / 2);
                ret += quard(y + size / 2, x, size / 2);
                ret += quard(y + size / 2, x + size / 2, size / 2); 
                ret += ')';
                return ret;  
            }
        } 
    }
    return string(1, a[y][x]); 
}
int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        for(int j = 0; j < n; j++){
            a[i][j] = s[j];
        }
    }
    cout << quard(0, 0, n) << '\n'; 
	return 0; 
}