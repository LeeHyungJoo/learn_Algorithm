using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int l, int r)
    {
       List<int> list = new List<int>();

        for(int i = l; i <= r; i++)
        {
            var temp = $"{i}";
           if(temp.All(x => x == '5' || x == '0'))
            {
                list.Add(i);
            }
        }
        list.Sort();
        return list.Count == 0 ? new int[]{-1} : list.ToArray();
    }
}