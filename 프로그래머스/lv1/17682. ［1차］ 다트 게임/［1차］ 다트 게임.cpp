#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	vector<int> scores;
	string num_buf;

	for (int i = 0; i < dartResult.size(); )
	{
		if (isdigit(dartResult[i]))
		{
			num_buf.push_back(dartResult[i]);
			i++;
		}
		else
		{
			int score = atoi(num_buf.c_str());
			num_buf.clear();

			switch (dartResult[i])
			{
			case 'S':
				break;
			case 'D':
				score *= score;
				break;
			case 'T':
				score *= (score * score);
				break;
			}

			if (i + 1 < dartResult.size() && !isdigit(dartResult[i + 1]))
			{
				switch (dartResult[i + 1])
				{
				case '*':
					if (scores.empty())
					{
						score *= 2;
					}
					else
					{
						scores.back() *= 2;
						score *= 2;
					}
					break;
				case '#':
					score *= -1;
					break;
				}
				i++;
			}

			i++;
			scores.push_back(score);
		}
	}

	return accumulate(scores.begin(), scores.end(), 0);
}