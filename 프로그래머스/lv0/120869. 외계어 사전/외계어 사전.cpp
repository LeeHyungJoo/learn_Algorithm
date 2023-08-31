#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
	int answer = 0;
	vector<int> dic_count;
	dic_count.resize(dic.size(), 0);

	for (int i = 0; i < dic.size(); i++)
		for (auto ch : spell)
			if (dic[i].find(ch[0]) != string::npos)
				dic_count[i]++;

	int size = spell.size();
	for (auto count : dic_count)
	{
		if (count == size)
			return 1;
	}

    return 2;
}
