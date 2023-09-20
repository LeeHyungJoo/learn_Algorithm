#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
	int answer = 0;

	for (int i_f = 0; i_f < number.size(); i_f++)
	{
		for (int i_s = i_f + 1; i_s < number.size(); i_s++)
		{
			for (int i_t = i_s + 1; i_t < number.size(); i_t++)
			{
				if (number[i_f] + number[i_s] + number[i_t] == 0)
					answer++;
			}
		}
	}

	return answer;
}