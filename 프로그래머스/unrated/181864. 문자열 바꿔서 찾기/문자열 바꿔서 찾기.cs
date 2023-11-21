using System;

public class Solution {
    public int solution(string myString, string pat) {
        myString = myString.Replace('A', 'b');
        myString = myString.Replace('B', 'a');
        myString = myString.ToUpper();

        return myString.Contains(pat) ? 1 : 0;
    }
}