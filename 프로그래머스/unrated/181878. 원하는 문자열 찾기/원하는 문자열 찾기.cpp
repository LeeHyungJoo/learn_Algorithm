#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) {
    transform(myString.begin(), myString.end(), myString.begin(), [](char c) { return tolower(c);});
    transform(pat.begin(), pat.end(), pat.begin(), [](char c) { return tolower(c);});
    return myString.find(pat) != myString.npos;
}