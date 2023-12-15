using System;
using System.Linq;

public class Solution {
    public string solution(string my_string, int[,] queries)
    {
        var myStrArray = my_string.AsSpan().ToArray();
        for (int i  = 0; i < queries.GetLength(0); i++)
        {
            var t = myStrArray.Skip(queries[i, 0]).Take(queries[i,1] - queries[i, 0] + 1).Reverse().ToArray();
            for(int idx = queries[i,0]; idx <= queries[i,1]; idx++)
                myStrArray[idx] = t[idx - queries[i,0]];
        }
        return new string (myStrArray);
    }
}