#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
	for (auto& c : myString)
	{
		if (isupper(c))
			continue;

		c = toupper(c);
	}
    return myString;
}