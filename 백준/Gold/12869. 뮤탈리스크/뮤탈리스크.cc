#define _CRT_SECURE_NO_WARNINGS
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
#include <list>

using namespace std;

const int INF = 987654321;
int dp[64][64][64], a[3], n, visited[64][64][64];
int _a[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}
};
struct A {
    int a, b, c;
};
queue<A>q;
int solve(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({ a, b, c });
    while (q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (visited[0][0][0]) break;
        for (int i = 0; i < 6; i++) {
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);
            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({ na, nb, nc });
        }
    }
    return visited[0][0][0] - 1;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(a[0], a[1], a[2]) << "\n";
    return 0;
}