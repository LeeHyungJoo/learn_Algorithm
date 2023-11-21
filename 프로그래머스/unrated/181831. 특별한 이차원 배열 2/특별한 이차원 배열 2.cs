using System;
using System.Linq;

public class Solution {
    public int solution(int[,] arr) {
        int n = arr.GetLength(0);
        return Enumerable.Range(0, n).All(i => Enumerable.Range(0, n).All(j => arr[i, j] == arr[j, i])) ? 1 : 0;
    }
}