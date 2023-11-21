using System;

public class Solution {
    public int solution(string myString, string pat) {
        myString = myString.Replace('A', 'b').Replace('B','a');

        return myString.ToUpper().Contains(pat) ? 1 : 0;
    }
}