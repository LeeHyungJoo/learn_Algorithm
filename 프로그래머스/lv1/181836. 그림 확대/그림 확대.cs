using System;
using System.Linq;
using System.Text;

public class Solution {
    public string[] solution(string[] picture, int k)
    {
        string[] answer = new string[picture.Length * k];
        for(int i = 0; i < answer.Length; i++)
        {
            var sb = new StringBuilder();
            for(int x = 0; x < picture[i/ k].Length; x++)
            {
                sb.Append(Enumerable.Repeat(picture[i/ k][x], k).ToArray());
            }
            answer[i] = sb.ToString();
        }
        return answer;
    }
}