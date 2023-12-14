using System;
using System.Linq;

public class Solution {
    public int solution(int[] arr)
    {
        int answer = 0;

        int[] last = new int[arr.Length];
        while (true)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] >= 50 && arr[i] % 2 == 0)
                {
                    arr[i] >>= 1;
                }
                else if (arr[i] < 50 && arr[i] % 2 == 1)
                {
                    arr[i] = arr[i] * 2 + 1;
                }
            }

            if (last.SequenceEqual<int>(arr))
            {
                break;
            }

            answer++;
            Array.Copy(arr, last, arr.Length);
        }


        return answer == 1 ? 0 : answer;
    }
}