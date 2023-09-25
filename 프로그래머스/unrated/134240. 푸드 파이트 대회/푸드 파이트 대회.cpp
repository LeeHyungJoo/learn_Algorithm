#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
	string answer = "";
	int size = 0; 
	for (int i = 1 ; i < food.size() ; i++)
	{
		size += food[i] / 2;
	}
	size = size * 2  + 1; 

	answer.resize(size, '0');

	int last_idx = 0; 
	for (int f_idx = 1; f_idx < food.size(); f_idx++)
	{
		int count = food[f_idx] / 2;

		for (int idx = 0; idx < count; idx++)
		{
			answer[last_idx + idx] = answer[size - last_idx - idx - 1] = (char)(f_idx + '0');
		}

		last_idx += count;
	}

	return answer;
}