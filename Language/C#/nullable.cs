using System;
using static System.Console;

namespace ConsloeApplication
{
	class Program
	{
		static void Main(String[] args)
		{
			int? a = null;
			int b = 4;

			if (a.HasValue == false)
			{
				WriteLine("a의 HasValue: " + a.HasValue );
				WriteLine("a에 값을 입력하세요.");
			}
			else
			{
				WriteLine("a의 HasValue: " + a.HasValue);
				WriteLine(a + b);
			}
		}

	}
}

