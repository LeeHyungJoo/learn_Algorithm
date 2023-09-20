#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	sort(strings.begin(), strings.end(), [n](const string& lhs, const string& rhs) { return lhs[n] == rhs[n] ? lhs < rhs : lhs[n] < rhs[n];});
	return strings;
}