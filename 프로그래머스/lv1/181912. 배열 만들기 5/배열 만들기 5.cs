using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(string[] intStrs, int k, int s, int l) {
        IEnumerable<int> list = new List<int>();
        foreach (var intStr in intStrs)
        {
            var target = Convert.ToInt32(intStr.Substring(s, l));
            if(target > k)
                list = list.Append(target);
        }
        return list.ToArray();
    }
}