#include <iostream>

using namespace std;

int N, M;
int cnt;

int stages[20] = {};

void FindMinMoveCount(int s_idx, int left, int right, int& len)
{
	if (s_idx == cnt)
	{
		return;
	}

	int target = stages[s_idx];
	int gap = 0;
	if (left <= target && target <= right)
	{
		FindMinMoveCount(s_idx + 1, left, right, len);
	}
	else if (target < left)
	{
		gap = left - target;
		len += gap;
		FindMinMoveCount(s_idx + 1, left - gap, right - gap, len);
	}
	else if (right < target)
	{
		gap = target - right;
		len += gap;
		FindMinMoveCount(s_idx + 1, left + gap, right + gap, len);
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> N >> M;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) cin >> stages[i];

	int answer = 0;
	FindMinMoveCount(0, 1, M, answer);
	cout << answer;
	return 0;
}