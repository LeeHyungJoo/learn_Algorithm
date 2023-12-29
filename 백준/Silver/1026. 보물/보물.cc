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

int N;
int A[50];
int B[50];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < N; i++)cin >> B[i];

	sort(A, A + N);
	sort(B, B + N);

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += (A[i] * B[N - i - 1]);
	}

	cout << answer;
	return 0;
}