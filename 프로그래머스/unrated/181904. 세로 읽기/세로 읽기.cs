using System;

public class Solution {
    public string solution(string my_string, int m, int c) {
        string answer = "";
        for(int i = 0; i < my_string.Length; i += m)
        {
            if(i + c - 1 < my_string.Length)
            {
                answer += my_string[i + c - 1];
            }
        }
        return answer;
    }
}