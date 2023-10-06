#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

const int ENDTIME = 48 * 60;


int ConvertToMinute(string time)
{
	return atoi(time.substr(0, 2).c_str()) * 60 + (atoi(time.substr(3, 2).c_str()));
}

string ConvertToTimeStr(int time)
{
	int hour = time / 60;
	string hour_str = to_string(hour);
	if (hour_str.size() == 1)
		hour_str.insert(0, "0");

	int min = time % 60;
	string min_str = to_string(min);
	if (min_str.size() == 1)
		min_str.insert(0, "0");

	return hour_str.append(":").append(min_str);
}


int  main()
{
	int count;
	cin >> count;

	int l_score = 0, r_score = 0;
	int l_time = 0, r_time = 0;
	pair<int, int> prev = { -1,-1 };

	for (int i = 0; i < count ; i++)
	{
		int team_idx;
		cin >> team_idx;

		string time;
		cin >> time;

		if (prev.first != -1)
		{
			if (l_score > r_score)
			{
				l_time += ConvertToMinute(time) - prev.second;
			}
			else if (r_score > l_score)
			{
				r_time += ConvertToMinute(time) - prev.second;
			}
		}

		team_idx == 1 ? ++l_score : ++r_score;
		prev = make_pair(team_idx, ConvertToMinute(time));
	}

	if (ENDTIME != prev.second)
	{
		if (l_score > r_score)
		{
			l_time += ENDTIME - prev.second;
		}
		else if (r_score > l_score)
		{
			r_time += ENDTIME - prev.second;
		}
	}

	cout << ConvertToTimeStr(l_time) << "\n";
	cout << ConvertToTimeStr(r_time) <<"\n";

	return 0;
}