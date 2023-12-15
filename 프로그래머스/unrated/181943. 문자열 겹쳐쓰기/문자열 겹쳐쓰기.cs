using System;

public class Solution {
    public string solution(string my_string, string overwrite_string, int s) {
        var answer = my_string.ToCharArray();
        for (int i = 0; i <overwrite_string.Length;i++)
            answer[s+i] = overwrite_string[i];
        return new string(answer);
    }
}