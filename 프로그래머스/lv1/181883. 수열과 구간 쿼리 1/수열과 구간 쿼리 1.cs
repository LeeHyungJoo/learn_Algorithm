using System;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) {
        for(int i = 0; i < queries.GetLength(0); i++)
        {
            for (int x = queries[i, 0]; x <= queries[i, 1]; x++)
                arr[x]++;
        }

        return arr;
    }
}