#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int soldierCnt, int shieldCnt, vector<int> enemySoldierWaves) {
	int round = 0;
	priority_queue<int> PQ;

	for (auto enemySoldierCnt : enemySoldierWaves)
	{
		PQ.push(enemySoldierCnt);
		soldierCnt -= enemySoldierCnt;

		if(soldierCnt < 0)
		{
			if (shieldCnt == 0)
				break;

			shieldCnt--;
			soldierCnt += PQ.top();
			PQ.pop();
		}

		round++;
	}

	return round;
}
