using System;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string my_string) {
        var strList = new List<string>();
        for(int offset = 0; offset < my_string.Length; offset++)
        {
            strList.Add(my_string.Substring(offset, my_string.Length - offset));
        }
        strList.Sort();
        return strList.ToArray();
    }
}