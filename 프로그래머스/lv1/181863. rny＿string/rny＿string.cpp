#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
	string answer = "";
	for (auto s : rny_string)
	{
		if (s == 'm')
		{
			answer.push_back('r');
			answer.push_back('n');
		}
		else
			answer.push_back(s);
	}
	
	return answer;
}