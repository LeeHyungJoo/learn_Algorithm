using System;
using System.Linq;

public class Solution {
    int[] check = new int[31];

    public int solution(string[] strArr)
    {
        foreach(var s in strArr)
            check[s.Length]++;

        
                return check.Max();
    }
}