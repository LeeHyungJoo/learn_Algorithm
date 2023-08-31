#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	for (int x = 0; x < arr1.size(); x++)
		for (int y = 0; y < arr1[x].size(); y++)
			arr1[x][y] += arr2[x][y];
	return arr1;
}