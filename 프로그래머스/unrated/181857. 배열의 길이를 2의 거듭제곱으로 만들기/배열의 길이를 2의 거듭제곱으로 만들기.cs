using System;

public class Solution {
    public int[] solution(int[] arr) {
        int pow = 1;
        while( arr.Length > pow)
        {
            pow <<= 1;
        }

        int[] answer = new int[pow];
        Array.Copy(arr, answer, arr.Length);
        return answer;
    }
}