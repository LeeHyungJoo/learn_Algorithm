using System;

public class Solution {
    int[] dy = { 0, 1, 0, -1 };
    int[] dx = { 1, 0, -1, 0 };

    public int[,] solution(int n)
    {
        int[,] answer = new int[n,n];

        int dir = 0;
        var start = (0, 0);
        int value = 0;
        answer[0, 0] = ++value;
        bool finalCheck = false;
        while(true)
        {
            var next = (start.Item1 + dy[dir % 4], start.Item2 + dx[dir % 4]);
            if(next.Item1 <0 || next .Item2 <0 || next.Item1 > n-1 || next.Item2 > n-1 || answer[next.Item1, next.Item2] != 0)
            {
                if (finalCheck)
                    break;
                finalCheck = true;
                dir++;
                continue;
            }

            finalCheck = false;
            answer[next.Item1, next.Item2] = ++value;
            start = next;
        }

        return answer;
    }
}