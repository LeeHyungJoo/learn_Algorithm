using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] rank, bool[] attendance) {
        List<int> rankList = rank.ToList();
        var result = rankList.Select((r, i) => new { Rank = r, Attendance = attendance[i], Index = i }).Where(s => s.Attendance).OrderBy(s => s.Rank).Take(3).Select((s, index) => s.Index).ToArray();
        return result[0] * 10000 + result[1] * 100 + result[2];
    }
}