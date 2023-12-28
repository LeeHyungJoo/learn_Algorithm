using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        Stack<int> stack = new Stack<int>();
        for(int i = 0; i < arr.Length; i++)
        {
            if(stack.Count == 0)
            {
                stack.Push(arr[i]);
            }
            else
            {
                 if(stack.Peek() == arr[i])
                {
                    stack.Pop();
                }
                else
                {
                    stack.Push(arr[i]);
                }
            }
        }
        return stack.Count == 0 ? new int[]{-1} : stack.Reverse().ToArray();
    }
}