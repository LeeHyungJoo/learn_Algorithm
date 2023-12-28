#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
	vector<string> numberStrs(numbers.size());
	transform(numbers.begin(), numbers.end(), numberStrs.begin(), [](int x) {return to_string(x); });

	sort(numberStrs.begin(), numberStrs.end(), [](const string& lhs, const string& rhs) {return (lhs + rhs) > (rhs + lhs); });

	string answer;
	for (const auto& str : numberStrs)
		answer += str;
	
	auto zero = answer.find_first_not_of('0');
	return zero != string::npos ? answer.substr(zero) : "0";
}
