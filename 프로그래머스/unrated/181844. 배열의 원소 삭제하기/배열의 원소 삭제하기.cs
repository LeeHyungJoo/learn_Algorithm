using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr, int[] delete_list)
    {
        (var arr_list, var del_list) = (arr.ToList(), delete_list.ToList());
        
        arr_list.RemoveAll(x => del_list.Contains(x));

        return arr_list.ToArray();
    }
}