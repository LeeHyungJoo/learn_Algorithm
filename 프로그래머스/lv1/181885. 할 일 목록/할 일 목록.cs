using System;
using System.Linq;

public class Solution {
    public string[] solution(string[] todo_list, bool[] finished)
    {
        return todo_list.AsQueryable().Where((item, index) => !finished[index]).ToArray(); ;
    }
}