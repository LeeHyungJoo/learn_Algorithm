#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {

	unordered_map<string, int> yearning_map;
	for (int i = 0; i < name.size(); i++)
		yearning_map[name[i]] = yearning[i];


	vector<int> answer(photo.size(), 0);
	for (int i = 0; i < photo.size();i++)
	{
		for (int j = 0; j < photo[i].size(); j++)
		{
			answer[i] += yearning_map[photo[i][j]];
		}
	}
	return answer;
}