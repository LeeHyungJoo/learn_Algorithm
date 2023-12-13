using System;

public class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        foreach(int t in num_list)
        {
            int x = t;
            while(true)
            {
                if (x == 1)
                    break;

                if ((x & 1) == 0)
                    x /= 2;
                else
                    x = (x - 1) / 2;
                answer++;
            }
        }
        return answer;
    }
}