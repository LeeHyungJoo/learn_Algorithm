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

	int last_num_l = 9;
	int last_num_r = 11;
	bool rCheck = false;
	for (auto number : numbers)
	{
		int c_x = number % 3;
		if (c_x == 1)
		{
			int dist_rc = dist(last_num_r / 3, last_num_r % 3, number / 3, 1);
			int dist_lc = dist(last_num_l / 3, last_num_l % 3, number / 3, 1);

			if (dist_rc == dist_lc)
				rCheck = hand.find('r') != hand.npos;
			else
				rCheck = dist_rc < dist_lc;
		}
		else
			rCheck = c_x != 0;

		if (rCheck)
			last_num_r = number;
		else
			last_num_l = number;

		answer.push_back(rCheck ? 'R' : 'L');
	}

	return answer;
}