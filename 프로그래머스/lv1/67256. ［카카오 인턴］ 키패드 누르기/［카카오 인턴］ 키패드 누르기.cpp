#include <string>
#include <vector>

using namespace std;
int dist(int y1, int x1, int y2, int x2)
{
	return abs(y1 - y2) + abs(x1 - x2);
}

string solution(vector<int> numbers, string hand) {
	string answer = "";

	for (auto& number : numbers)
	{
		if (number == 0)
			number = 10;
		else
			number--;
	}

	int last_num_r = 11;
	int last_num_l = 9;
	bool rCheck = false;
	for (auto number : numbers)
	{
		int c_x = number % 3;
		switch (c_x)
		{
		case 0:
			rCheck = false;
			break;
		case 2:
			rCheck = true;
			break;
		case 1:
		{
			int r_y = last_num_r / 3;
			int r_x = last_num_r % 3;

			int l_y = last_num_l / 3;
			int l_x = last_num_l % 3;

			int c_y = number / 3;

			int dist_rc = dist(r_y, r_x, c_y, c_x);
			int dist_lc = dist(l_y, l_x, c_y, c_x);

			if (dist_rc == dist_lc)
				rCheck = hand.find('r') != hand.npos;
			else
				rCheck = dist_rc < dist_lc;
		}
		break;
		}

		if (rCheck)
		{
			last_num_r = number;
			answer.push_back('R');
		}
		else
		{
			last_num_l = number;
			answer.push_back('L');
		}
	}

	return answer;
}