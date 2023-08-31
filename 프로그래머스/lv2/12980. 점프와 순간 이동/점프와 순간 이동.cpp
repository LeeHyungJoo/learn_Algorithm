#include <iostream>
#include <bitset>
using namespace std;

int solution(int n)
{
    return bitset<32>(n).count();
}