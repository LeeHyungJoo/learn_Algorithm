using System;
using System.Linq;

public class Solution {
    public int solution(int a, int d, bool[] included)
    {
        return included.Select((x, i) => x ? a + d * i : 0).Sum(); ;
    }
}