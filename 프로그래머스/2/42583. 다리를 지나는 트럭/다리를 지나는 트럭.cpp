#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> check;
    for (int c = 0; c < bridge_length; c++)
        check.push(0);

    int currentSum = 0;
    int answer = 0;
    for (int i = 0; !check.empty() && i <= truck_weights.size();)
    {
        currentSum -= check.front();
        check.pop();

        if (i != truck_weights.size())
        {
            if (currentSum + truck_weights[i] <= weight)
            {
                currentSum += truck_weights[i];
                check.push(truck_weights[i]);
                i++;
            }
            else
            {
                check.push(0);
            }
        }

        answer++;
    }

    return answer;
}