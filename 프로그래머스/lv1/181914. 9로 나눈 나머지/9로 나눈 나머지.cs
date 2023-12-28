using System;
using System.Linq;

public class Solution {
    public int solution(string number) {
        return number.AsEnumerable().Sum(x => x - '0') % 9 ;
    }
}