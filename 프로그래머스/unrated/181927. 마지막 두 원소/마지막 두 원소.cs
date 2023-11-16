using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] num_list) {
        var t = num_list.ToList();
        t.Add(num_list[num_list.Length - 1] > num_list[num_list.Length - 2] ? num_list[num_list.Length - 1] - num_list[num_list.Length - 2] : num_list[num_list.Length - 1] * 2);
        return t.ToArray();
    }
}