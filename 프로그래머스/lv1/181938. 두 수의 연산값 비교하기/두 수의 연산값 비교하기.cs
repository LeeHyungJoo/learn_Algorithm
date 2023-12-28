using System;

public class Solution {
    public int solution(int a, int b) {
        (int a1, int a2) = (2 * a * b, int.Parse($"{a}{b}"));

        return a1 < a2 ? a2 : a1;
    }
}