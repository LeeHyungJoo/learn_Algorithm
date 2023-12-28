#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString) {
	transform(myString.begin(), myString.end(), myString.begin(), [](const char& c) { return tolower(c);});
	return myString;
}