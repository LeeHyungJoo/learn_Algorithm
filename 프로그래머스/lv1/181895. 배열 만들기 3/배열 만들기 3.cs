using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] arr, int[,] intervals) {
        List<int> answer = new List<int>();
        for(int i = 0; i < intervals.GetLength(0); i++)
        {
            answer.AddRange(arr.Skip(intervals[i, 0]).Take(intervals[i, 1] - intervals[i, 0] + 1) );
        }

        return answer.ToArray();
    }
}