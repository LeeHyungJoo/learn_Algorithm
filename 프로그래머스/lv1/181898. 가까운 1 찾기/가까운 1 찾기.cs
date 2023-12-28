
using System;
using System.Linq;

public class Solution {
    public int solution(int[] arr, int idx) {
        return Array.FindIndex(arr, idx, t => t == 1); 
    }
}