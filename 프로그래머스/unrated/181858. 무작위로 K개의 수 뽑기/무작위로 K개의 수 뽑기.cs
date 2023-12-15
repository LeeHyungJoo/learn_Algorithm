using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] arr, int k) {
        int[] answer = new int[k];
        Array.Fill(answer, -1);
        HashSet<int> check = new HashSet<int>();
        foreach (var a  in arr)
        {
            if (check.Count == k)
                break;
            check.Add(a);
        }
        Array.Copy(check.ToArray(), answer, check.Count);
        return answer;
    }
}