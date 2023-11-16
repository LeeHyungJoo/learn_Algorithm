using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[] names) {
        List<string> answer = new List<string>();

        for(int i = 0; i < names.Length; i++)
        {
            if(i % 5 == 0)
                answer.Add(names[i]);
        }

        return answer.ToArray(); 
    }
}