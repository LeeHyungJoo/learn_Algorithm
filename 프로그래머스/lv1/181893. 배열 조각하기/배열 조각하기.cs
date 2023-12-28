using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int[] query) {
        var answer = arr.ToList().AsEnumerable();
        for(int i = 0; i < query.Length; i++)
        {
            if ((i & 1) == 1)
            {
                answer = answer.Skip(query[i]).Take(arr.Length - query[i]);
            }
            else
            {
                answer = answer.Take(query[i] + 1);
            }
        }
        return answer.ToArray();
    }
}