using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] date1, int[] date2) {
        Func<int,int,int> lamda = (int x, int i) =>
        {
            if (i == 2) return x;
            else return (int)Math.Pow(10, (int)Math.Pow(2, 2 - i)) * x;
        };

        var sum1 = date1.ToList().Select(lamda).Sum();
        var sum2 = date2.ToList().Select(lamda).Sum();
        return sum1 <sum2 ? 1 : 0;
    }
}