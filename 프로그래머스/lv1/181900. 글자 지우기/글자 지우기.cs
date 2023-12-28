using System;
using System.Linq;

public class Solution {
    public string solution(string my_string, int[] indices) {
        return  string.Concat(my_string.Where((x, i) => !indices.Any(idx => idx == i)));
    }
}