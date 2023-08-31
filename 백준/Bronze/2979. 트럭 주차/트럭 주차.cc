#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int dc_pay[3];
	cin >> dc_pay[0] >> dc_pay[1] >> dc_pay[2];

	int t1, t2;
	unordered_map<int, int> truck_count;
	for (int t = 0; t < 3; t++)
	{
		cin >> t1 >> t2;
		for (int t = t1; t < t2;t++) truck_count[t]++;
	}

	int whole_pay = 0;
	for (auto tc : truck_count)
	{
		whole_pay += dc_pay[tc.second - 1] * tc.second;
	}
	cout << whole_pay;
}