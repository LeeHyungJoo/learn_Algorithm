using System;

public class Solution {
    public int[,] solution(int n) {
        int[,] answer = new int[n,n];
        for(int i = 0; i < answer.GetLength(0); i++)
            for(int j = 0; j < answer.GetLength(1); j++)
                answer[i,j] = i == j ? 1 : 0;

        return answer;
    }
}