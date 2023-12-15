using System;
using System.Text;

public class Example
{
    public static void Main()
    {
        String s;

        Console.Clear();
        s = Console.ReadLine();
        
        StringBuilder  stringBuilder = new StringBuilder();
        foreach (var c in s)
        {
            if(char.IsUpper(c))
                stringBuilder.Append(char.ToLower(c));
            else if (char.IsLower(c))
                stringBuilder.Append(char.ToUpper(c));
        }

        Console.WriteLine(stringBuilder);
    }
}