using System;
using System.Linq;

public class Solution {
    public string solution(string str1, string str2) {
        char[] chars = new char[str1.Length + str2.Length];
        var str1Iter = str1.GetEnumerator();
        var str2Iter = str2.GetEnumerator();
        str1Iter.MoveNext();
        str2Iter.MoveNext();

        for (int i = 0; i < chars.Length; i++)
        {
            if ((i & 1) == 1)
            {
                chars[i] = str2Iter.Current;
                str2Iter.MoveNext();
            }
            else
            {
                chars[i] = str1Iter.Current;
                str1Iter.MoveNext();
            }
        }

        return new string(chars);
    }
}