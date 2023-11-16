using System;

public class Solution {
    public int solution(int a, int b) {
        int ret;
        if(a % 2 == 0 && b % 2 == 0)
        {
            ret = Math.Abs(a - b);
        } 
        else if (a % 2 == 1 && b % 2 == 1) 
        {
            ret = (int)Math.Pow(a,2) + (int)Math.Pow(b,2);
        }
        else
        {
            ret = 2 * (a + b);
        }

        return ret;
    }
}