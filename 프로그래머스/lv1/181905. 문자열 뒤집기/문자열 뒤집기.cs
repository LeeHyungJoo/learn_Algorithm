using System;
using System.Linq;

public class Solution {
    public string solution(string my_string, int s, int e) {
        var answer = my_string.ToArray();

        Array.Reverse(answer, s, e - s + 1);
        
        return string.Concat(answer);
    }
}