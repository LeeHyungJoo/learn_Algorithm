using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        int first = Array.FindIndex(arr, x => x == 2);
        int last = Array.FindLastIndex(arr, x => x == 2);
        return (first < 0) ? new int[] { -1 } : arr.Skip(first).Take(last - first+ 1).ToArray();
    }
}