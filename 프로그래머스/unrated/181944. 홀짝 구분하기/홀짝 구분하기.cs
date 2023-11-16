using System;

public class Example
{
    public static void Main()
    {
        String[] s;

        Console.Clear();
        s = Console.ReadLine().Split(' ');

        int a = Int32.Parse(s[0]);
        if((a&1) == 0)
        {
            Console.WriteLine($"{a} is even");
        }
        else
        {
            Console.WriteLine($"{a} is odd");
        }
    }
}