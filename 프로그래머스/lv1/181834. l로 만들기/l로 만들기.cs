using System;
using System.Linq;

public class Solution {
    public string solution(string myString) {
        return new string (myString.Select(t => t < 'l' ? 'l' : t).ToArray());
    }
}