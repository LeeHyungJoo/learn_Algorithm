using System;
using System.Linq;

public class Solution {
    public int[] solution(int n, int[] slicer, int[] num_list) {
        int[] answer = new int[] { };
        switch(n)
        {
            case 1:
                answer = num_list.Where((x, i) => i <= slicer[1]).ToArray();
                break;
            case 2:
                answer = num_list.Where((x, i) => i >= slicer[0]).ToArray();
                break;
            case 3:
                answer = num_list.Where((x, i) => i <= slicer[1] && i >= slicer[0]).ToArray();
                break;
            case 4:
                answer = num_list.Where((x, i) => i <= slicer[1] && i >= slicer[0] && (i - slicer[0]) % slicer[2] == 0 ).ToArray();
                break;
        }
        return answer;
    }
}