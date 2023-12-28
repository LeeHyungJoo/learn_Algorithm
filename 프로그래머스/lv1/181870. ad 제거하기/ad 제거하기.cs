using System;
using System.Linq;

public class Solution {
    public string[] solution(string[] strArr) {
      return strArr.AsQueryable().Where(t => !t.Contains("ad")).ToArray();
    }
}