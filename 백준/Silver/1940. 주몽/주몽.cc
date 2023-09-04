#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>

using namespace std;


int main()
{
	int material_count = 0;
	cin >> material_count;

	int target_value = 0;
	cin >> target_value;

	vector<int> materials(material_count);
	for (int i = 0; i < materials.size(); i++)
		cin >> materials[i];

	int answer = 0;
	for(int i = 0 ; i < materials.size() ; i++)
		for (int j = i + 1; j < materials.size(); j++)
		{
			if (materials[i] + materials[j] == target_value)
				answer++;
		}

	cout << answer;
	return 0;
}