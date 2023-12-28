using System;
using System.Collections;
using System.Linq;
using System.Reflection;

public class Solution {
    public int solution(string binomial) {
        int answer = 0;
        foreach (var splits in new char[]{ '+', '*','-' })
        {
            var splitedStr = binomial.Split(splits);
            if (splitedStr.Length == 2)
            {
                switch(splits)
                {
                    case '+':
                        answer = int.Parse(splitedStr[0]) + int.Parse(splitedStr[1]);
                        break;
                    case '-':
                        answer = int.Parse(splitedStr[0]) - int.Parse(splitedStr[1]);
                        break;
                    case '*':
                        answer = int.Parse(splitedStr[0]) * int.Parse(splitedStr[1]);
                        break;
                }
                break;
            }
        }
        return answer;
    }
}