using System;
using System.Text;
using System.Linq;

public class Solution {
    public string solution(string a, string b)
    {
        int carry = 0;
        StringBuilder answer = new StringBuilder();
        for (int i = a.Length - 1, j = b.Length - 1; i >= 0 || j >= 0 || carry != 0;)
        {
            int aNum = 0;
            if (i >= 0)
            {
                aNum = Convert.ToInt32(a[i--]) - '0';
            }

            int bNum = 0;
            if (j >= 0)
            {
                bNum = Convert.ToInt32(b[j--]) - '0';
            }

            var result = Convert.ToString(aNum + bNum + carry);
            if (carry == 1) carry = 0;

            answer.Append(result.Last());
            if (result .Length > 1)
            {
                carry = 1;
            }
        }
        var charArr = answer.ToString().ToArray();
        Array.Reverse(charArr);
        return new string(charArr);
    }
}