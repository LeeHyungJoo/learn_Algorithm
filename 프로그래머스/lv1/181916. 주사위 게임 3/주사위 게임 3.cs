using System.Linq;
using System.Text;
using System.Collections.Generic;

public class Solution {
    public int solution(int a, int b, int c, int d) {
        Dictionary<int, int> check = (new int[] { a, b, c, d }).ToLookup(key => key).ToDictionary(x => x.Key, x => x.Count());

        int answer = 0;
        switch (check.Count)
        {
            case 4:
                answer = check.Select(x => x.Key).Min();
                break;
            case 3:
                answer =  check.Where(x => x.Value == 1).Select(x => x.Key).Aggregate((lhs, rhs) => lhs * rhs);
                break;
            case 2:
                if (check.First().Value == 2)
                {
                    var arr = check.Select(x => x.Key).ToArray();
                    answer = (arr[0] + arr[1]) * (System.Math.Abs(arr[0] - arr[1]));
                }
                else
                {
                    var p = check.Where(x => x.Value == 3).Select(x => x.Key).FirstOrDefault();
                    var q = check.Where(x => x.Value == 1).Select(x => x.Key).FirstOrDefault();
                    answer = (int)System.Math.Pow(10 * p + q, 2);
                }
                break;
            case 1:
                answer = check.First().Key * 1111;
                break;
        }


        return answer;
    }
}