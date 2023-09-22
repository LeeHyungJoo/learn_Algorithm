#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    pair<int, int> arr[9];
    vector<int> v;

    for(int i=0; i<dungeons.size(); i++){
        arr[i+1] = {dungeons[i][0], dungeons[i][1]};
        v.push_back(i+1);
    }

    do{
        int tmp = k;
        int cnt = 0;        
        for(int i=0; i<v.size(); i++){
            if(tmp >= arr[v[i]].first){
                cnt++;
                tmp -= arr[v[i]].second;
            } 
        }
        answer = max(answer, cnt);
    } while(next_permutation(v.begin(), v.end()));

    return answer;
}