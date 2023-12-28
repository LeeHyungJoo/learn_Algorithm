using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public string[] solution(string[] names)
    {
        return names.Where((name, index) => index % 5 == 0).ToArray();
    }
}