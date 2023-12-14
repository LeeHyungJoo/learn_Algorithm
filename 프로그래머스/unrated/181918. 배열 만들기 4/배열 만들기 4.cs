using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        Stack<int> stack = new Stack<int>();
        for(int i = 0; i < arr.Length;)
        {
            if(stack.Count == 0)
            {
                stack.Push(arr[i]);
                i++;
            }
            else
            {
                if(stack.Peek() < arr[i])
                {
                    stack.Push(arr[i]);
                    i++;
                }
                else
                {
                    stack.Pop();
                }

            }
        }
        return stack.Reverse().ToArray();
    }
}