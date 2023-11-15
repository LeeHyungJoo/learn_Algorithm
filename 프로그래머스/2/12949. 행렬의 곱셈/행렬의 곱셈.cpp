#include <string>
#include <vector>

using namespace std;
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	answer.resize(arr1.size());

	for (int i = 0; i < answer.size(); i++)
		answer[i].resize(arr2[0].size());

	int mul_c = arr1[0].size();

	for (int i = 0; i < answer.size(); i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
		{
			int result = 0;

			for (int m = 0; m < mul_c; m++)
			{
				result += arr1[i][m] * arr2[m][j];
			}
			answer[i][j] = result;
		}
	}

	return answer;
}
