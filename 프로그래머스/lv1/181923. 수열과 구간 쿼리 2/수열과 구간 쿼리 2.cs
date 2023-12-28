using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int[,] queries) {
        int[] answer = new int[queries.GetLength(0)];

        for (int i = 0; i < queries.GetLength(0); i++)
        {
            answer[i] = arr.Skip(queries[i, 0])
                .Take(queries[i, 1] - queries[i, 0] + 1)
                .Where(x => x > queries[i, 2])
                .DefaultIfEmpty(-1)
                .Min();
        }

        return answer;
    }
}