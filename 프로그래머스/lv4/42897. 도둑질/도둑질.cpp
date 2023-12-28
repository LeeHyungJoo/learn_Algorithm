#include <string>
#include <vector>

using namespace std;

int dp[1000000];

int solution(vector<int> money) {
    int answer = 0;

    dp[0] = money[0];
    dp[1] = money[0];
    
    for(int i = 2; i < money.size()-1; ++i)
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    
    answer = dp[money.size()-2];
    
    dp[0] = 0;
    dp[1] = money[1];
    
    for(int i = 2; i < money.size(); ++i)
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    
    answer = max(answer, dp[money.size()-1]);
    
    return answer;
}