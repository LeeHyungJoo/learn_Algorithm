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

int R, C;
vector<string> arr;
bool isFind = false;
pair<int, int> swan;
queue<pair<int, int>> sq, wq, tmpSQ, tmpWQ;
int dy[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
bool ch[1501][1501];

void swanBFS() {
	while (!sq.empty()) {
		int x = sq.front().first;
		int y = sq.front().second;
		sq.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dy[k][0];
			int ny = y + dy[k][1];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C || ch[nx][ny]) 
				continue;
			ch[nx][ny] = true;
			if (arr[nx][ny] == 'X') tmpSQ.push({ nx,ny });
			else if (arr[nx][ny] == '.') sq.push({ nx,ny });
			else if (arr[nx][ny] == 'L') {
				isFind = true;
				break;
			}
		}
	}
}

void waterBFS() {
	while (!wq.empty()) {
		int x = wq.front().first;
		int y = wq.front().second;
		wq.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dy[k][0];
			int ny = y + dy[k][1];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
			if (arr[nx][ny] == 'X') {
				arr[nx][ny] = '.';
				tmpWQ.push({ nx,ny });
			}
		}
	}
}

int meetDay() {
	int day = 0;
	while (!isFind) {
		swanBFS();
		if (isFind) break;
		waterBFS();
		sq = tmpSQ;
		wq = tmpWQ;
		while (!tmpSQ.empty()) tmpSQ.pop();
		while (!tmpWQ.empty()) tmpWQ.pop();
		day++;
	}

	return day;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		arr.push_back(str);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 'L') {
				swan.first = i;
				swan.second = j;
			}
			if (arr[i][j] != 'X') {
				wq.push({ i,j });
			}
		}
	}
	ch[swan.first][swan.second] = true;
	sq.push(swan);
	cout << meetDay() << "\n";
	return 0;
}