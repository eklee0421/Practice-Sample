using System;
using System.Threading;

//2초에 한 번씩 글자 색상과 위치가 랜덤으로 출력되는 소스
namespace ConsloeApplication
{
	class Program
	{
		static void Main(String[] args) {
			Console.SetWindowSize(100, 40);
			Random rand = new Random();
			ConsoleColor[] Color = { ConsoleColor.Blue, ConsoleColor.Cyan, ConsoleColor.Red, ConsoleColor.Yellow, ConsoleColor.Green, ConsoleColor.Magenta, ConsoleColor.Gray };

			while (true) {
				Console.Clear();
				for (int i = 0; i < 30; i++) {
					Console.ForegroundColor = Color[rand.Next(7)];
					Console.SetCursorPosition(rand.Next(100), rand.Next(40));
					Console.Write("Hello World!");
				}
				Thread.Sleep(200);
			}
		}
	}
}
