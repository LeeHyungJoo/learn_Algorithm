#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> um;
    int len = players.size();
    for(int i = 0; i < len; ++i) um[players[i]] = i;
    for(const auto& s : callings){
        int index = um[s];
        um[players[index - 1]]++;
        um[s]--;
        swap(players[index - 1], players[index]);        
    }
    return players;
}