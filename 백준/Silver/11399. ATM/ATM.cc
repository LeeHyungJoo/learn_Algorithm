#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[1000];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int answer = arr[0];
	int last = arr[0];
	for (int i = 1; i < N; i++)
	{
		last += arr[i];
		answer += last;
	}

	cout << answer;


	return 0;
}