using System;
using static System.Console;

namespace ConsloeApplication
{
	class Program
	{
		static void Main(String[] args)
		{
			if(args.Length == 0)
            {
				Console.WriteLine("사용법 : ConsoleApplication.exe <이름>");
				return;
            }

			WriteLine("Hello, {0}!", args[0]);
		}

	}
}

