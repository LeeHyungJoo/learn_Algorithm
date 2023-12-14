using System;

public class Solution {
    public string[] solution(string myStr)
    {
        var splitedStr = myStr.Split(new char[] { 'a', 'b', 'c' }, StringSplitOptions.RemoveEmptyEntries);
        return splitedStr.Length == 0 ? new string[] { "EMPTY" } : splitedStr;
    }
}