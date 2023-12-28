#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
	for (auto& c : my_string)
	{
		if (c == alp[0])
			c = toupper(c);
	}
	return my_string;
}