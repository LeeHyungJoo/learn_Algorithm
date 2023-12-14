using System;
using System.Linq;

public class Solution {
    public int solution(string[] order) {
        return order.Sum(x =>
        {
            if (x.Contains("cafelatte")) return 5000;
            return 4500;
        });
    }
}