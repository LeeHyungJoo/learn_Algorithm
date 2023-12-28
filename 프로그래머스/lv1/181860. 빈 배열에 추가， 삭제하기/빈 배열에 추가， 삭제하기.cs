using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] arr, bool[] flag) {
        List<int> list = new List<int>();
        for(int i = 0; i < flag.Length; i++)
        {
            if (flag[i])
            {
                list.AddRange(Enumerable.Repeat(arr[i], arr[i] * 2));
            }
            else
            {
                list.RemoveRange(list.Count - arr[i], arr[i]);
            }
        }
        return list.ToArray();
    }
}