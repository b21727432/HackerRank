using System;

namespace ConsoleApp14
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Random Sayilar Olusturuluyor...");
            Random rnd = new Random();
            int[] loto_sayilar = new int[6];
            for(int i = 0; i < 6; i++)
            {
                loto_sayilar[i] = rnd.Next(1, 49);
            }
            Console.WriteLine("Random Sayilar:");
            for(int i = 0; i < 6; i++)
            {
                Console.Write(loto_sayilar[i] + " ");
            }
        }
    }
}
