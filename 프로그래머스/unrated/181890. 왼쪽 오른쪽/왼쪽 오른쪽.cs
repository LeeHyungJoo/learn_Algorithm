using System;
using System.Linq;

public class Solution {
    public string[] solution(string[] str_list) {
        var strList = str_list.ToList();

        var idxL = strList.FindIndex(x => x == "l");
        var idxR = strList.FindIndex(x => x == "r");

        if(idxL != -1 && idxR != -1)
        {
            if (idxL < idxR)
                return strList.Take(idxL).ToArray();
            else 
                return strList.Skip(idxR + 1).ToArray();
        }
        else if(idxL != -1)
        {
            return strList.Take(idxL).ToArray();
        }
        else if( idxR != -1)
        {
            return strList.Skip(idxR + 1).ToArray();
        }
        else
        {
            return new string[] { };
        }
    }
}