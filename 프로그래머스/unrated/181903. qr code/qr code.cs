using System;
using System.Linq;
using System.Text;

public class Solution {
    public string solution(int q, int r, string code)
    {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i <code.Length - r; i += q)
        {
            sb.Append(code.Skip(i).ElementAt(r));
        }
        return sb.ToString();
    }
}