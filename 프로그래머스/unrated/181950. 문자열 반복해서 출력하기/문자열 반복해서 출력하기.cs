using System;
using System.Linq;

public class Example
{
    public static void Main()
    {
        String[] input;

        Console.Clear();
        input = Console.ReadLine().Split(' ');

        String s1 = input[0];
        int a = Int32.Parse(input[1]);
        
        Console.WriteLine(string.Concat(Enumerable.Repeat(s1, a)));
    }
}