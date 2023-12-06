using System;

public class Solution {
    public int solution(int a, int b, int c) {
        int answer = 0;
        if(a == b && a == c && b == c)
        {
            answer =(a + b + c) * ((int)Math.Pow(a,2) + (int)Math.Pow(b, 2) + (int)Math.Pow(c, 2)) * ((int)Math.Pow(a, 3) + (int)Math.Pow(b, 3) + (int)Math.Pow(c, 3)); 
        }
        else if (a != b && a != c && b != c)
        {
            answer = (a + b + c);
        }
        else
        {
            answer = (a + b + c) * ((int)Math.Pow(a, 2) + (int)Math.Pow(c, 2) + (int)Math.Pow(b, 2));
        }
        return answer;
    }
}