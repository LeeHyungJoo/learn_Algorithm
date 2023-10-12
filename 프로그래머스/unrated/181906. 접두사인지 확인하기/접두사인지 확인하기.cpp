#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
	return my_string.find(is_prefix,0) == 0;
}
