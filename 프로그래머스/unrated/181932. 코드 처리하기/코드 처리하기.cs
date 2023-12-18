using System;
using System.Linq;
using System.Text;

public class Solution {
    public string solution(string code) {
        StringBuilder sb = new StringBuilder();
        int mode = 0;
        for(int i = 0 ; i < code.Length;i++)
        {
            if(mode == 0)
            {
                if (code[i] == '1')
                    mode = mode == 0 ? 1 : 0;
                else if((i & 1) == 0)
                    sb.Append(code[i]);
            }
            else if(mode == 1)
            {
                if (code[i] == '1')
                    mode = mode == 0 ? 1 : 0;
                else if ((i & 1) == 1)
                    sb.Append(code[i]);
            }
        }

        return sb.Length == 0 ? "EMPTY" :  sb.ToString();
    }
}