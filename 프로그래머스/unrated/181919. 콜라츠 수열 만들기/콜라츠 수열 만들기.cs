using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int n) {
        List<int> list = new List<int>();
        while(n != 1)
        {
            list.Add(n);
            n = (n & 1) == 1 ? 3 * n + 1 : n >> 1;
        }
        list.Add(1);
        return list.ToArray();
    }
}