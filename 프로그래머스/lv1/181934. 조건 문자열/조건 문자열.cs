using System;

public class Solution {
    public int solution(string ineq, string eq, int n, int m)
    {
        switch(ineq)
        {
            case "<":
                if (eq == "=")
                    return Convert.ToInt32(n <= m);
                else
                    return Convert.ToInt32(n < m);
            case ">":
                if (eq == "=")
                    return Convert.ToInt32(n >= m);
                else
                    return Convert.ToInt32(n > m);
        }
        return 0;
    }
}