#include <string>
#include <vector>

using namespace std;
vector<int> Sorting(vector<int>);
vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer,indices;
    vector<int> sortArr = Sorting(array);
    vector<int>::const_iterator o_iter;
    vector<int>::const_iterator s_iter;

	for (auto& command : commands)
	{
		indices.clear();
		for (o_iter = array.begin() + command[0] - 1 ; o_iter < array.begin() + command[1]; ++o_iter)
			for (s_iter = sortArr.begin() ; s_iter != sortArr.end(); ++s_iter)
				if ((*o_iter) == (*s_iter))
				{
					indices.push_back(s_iter - sortArr.begin());
					break;
				}
			
		indices = Sorting(indices);
		answer.push_back(sortArr[indices[command[2]-1]]);
	}

	return answer;
}

vector<int> Sorting(vector<int> array)
{
	for (int i = 0; i < array.size() - 1; i++)
		for (int j = 0; j < array.size() - 1 - i; j++)
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}

	return array;
}