#include <string>
#include <vector>

using namespace std;

const int STRAIGHT = 100;
const int CURVE = 500;

int minCost = numeric_limits<int>::max();

int boardArr[25][25];
int visited[25][25];
int dp[25][25][4];
int N;

const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,1,0,-1 };

void DFS(int y, int x, int lastDir, int cost , bool first = false)
{
    if (y == N - 1 && x == N - 1)
    {
        minCost = min(minCost, cost);
        return;
    }

    if (cost > minCost)
    {
        return;
    }

    if (!first && dp[y][x][lastDir] != 0)
    {
        if (dp[y][x][lastDir] < cost)
            return;
    }

    dp[y][x][lastDir] = cost;

    visited[y][x] = 1;

    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny <0 || nx < 0 || ny > N - 1 || nx > N - 1 || boardArr[ny][nx] || visited[ny][nx])
        {
            continue;
        }

        if (lastDir == dir || first)
        {
            DFS(ny, nx, dir, cost + STRAIGHT);
        }
        else
        {
            DFS(ny, nx, dir, cost + STRAIGHT + CURVE);
        }
    }

    visited[y][x] = 0;
}

int solution(vector<vector<int>> board) {
    N = board.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            boardArr[i][j] = board[i][j];
        }
    }
    DFS(0, 0, 0, 0, true);
    return minCost;
}