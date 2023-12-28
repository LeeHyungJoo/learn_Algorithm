using System;

public class Solution {
    public string solution(string myString, string pat) {
        return myString.Substring(0, myString.LastIndexOf(pat) + pat.Length);
    }
}