using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int[] delete_list)
    {
        return arr.Except(delete_list).ToArray();
    }
}