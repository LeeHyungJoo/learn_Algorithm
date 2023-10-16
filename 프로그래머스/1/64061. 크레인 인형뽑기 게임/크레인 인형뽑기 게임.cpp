#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	vector<queue<int>> board_queue;
	board_queue.resize(board.size());
	for (int i = 0; i < board.size(); i++)
	{
		for (int x = 0; x < board[i].size() ; x++)
		{
			if (board[i][x] == 0)
				continue;

			board_queue[x].push(board[i][x]);
		}
	}

	stack<int> checks;

	for (auto move : moves)
	{
		int next = -1;
		if (!board_queue[move - 1].empty())
		{
			next = board_queue[move - 1].front();
			board_queue[move - 1].pop();
		}

		if (next < 0)
			continue;

		if (checks.empty())
		{
			checks.push(next);
		}
		else
		{
			if (checks.top() == next)
			{
				checks.pop();
				answer++;
			}
			else
			{
				checks.push(next);
			}
		}
	}

	return answer * 2;
}