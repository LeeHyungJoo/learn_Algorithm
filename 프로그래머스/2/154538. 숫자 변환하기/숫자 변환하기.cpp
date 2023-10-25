#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
	unordered_set<int> checks;
	queue<pair<int, int>> que;
	que.push(make_pair(x, 0));

	while (!que.empty())
	{
		auto next = que.front();
		que.pop();
		int v = next.first;
		int d = next.second;

		if (checks.find(v) != checks.end())
			continue;

		checks.insert(v);

		if (v < y)
		{
			que.push({ v * 3 , d + 1 });
			que.push({ v * 2 , d + 1 });
			que.push({ v + n, d + 1 });
		}
		else if (v == y)
		{
			return d;
		}
	}

	return -1;
}