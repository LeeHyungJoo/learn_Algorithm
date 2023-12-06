using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    Dictionary<int, char> checks = new Dictionary<int, char>
        {
            { +1 ,'w'},
            {  -1 ,'s'},
            { +10, 'd' },
            { -10, 'a' },
        };

    public string solution(int[] numLog)
    {
        string answer = "";
        
        for(int i = 1; i < numLog.Length; i++)
        {
            answer = string.Concat(answer, checks[numLog[i] - numLog[i-1]]);
        }

        return answer;
    }
}