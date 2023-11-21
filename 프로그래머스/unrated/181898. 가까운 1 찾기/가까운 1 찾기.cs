
using System;
using System.Linq;

public class Solution {
    public int solution(int[] arr, int idx) {
        var nextIndex = arr.Skip(idx).Select((value, index) => new { Value = value, Index = index + idx })
                                            .FirstOrDefault(x => x.Value == 1)?.Index ?? -1;
        return nextIndex;
    }
}