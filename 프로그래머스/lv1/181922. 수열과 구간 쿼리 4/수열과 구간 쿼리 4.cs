using System;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) {
        for(int i = 0; i < queries.GetLength(0); i++) 
        {
            for(int j = queries[i,0]; j <= queries[i,1]; j++)
            {
                if (j % queries[i, 2] != 0)
                    continue;

                arr[j]++;
            }
        }
        return arr;
    }
}