#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
	auto s1 = atoi(to_string(a).append(to_string(b)).c_str());
	auto s2 = atoi(to_string(b).append(to_string(a)).c_str());
	return s1 >= s2 ? s1 : s2;
}
