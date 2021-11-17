using System;

namespace ConsoleApp10
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("1. sayiyi girin : ");
            int sayi1 = Convert.ToInt32(Console.ReadLine());
            Console.Write("2. sayiyi girin : ");
            int sayi2 = Convert.ToInt32(Console.ReadLine());
            int sayi1toplam = 0;
            int sayi2toplam = 0;
            for(int i = 1; i < sayi1; i++)
            {
                if(sayi1 % i == 0)
                {
                    sayi1toplam = sayi1toplam + i;
                }
            }
            for(int i = 1; i < sayi2; i++)
            {
                if(sayi2 % i == 0)
                {
                    sayi2toplam = sayi2toplam + i;
                }
            }
            if(sayi1toplam == sayi2 && sayi2toplam == sayi1)
            {
                Console.WriteLine("Bu sayilar arkadas sayilardir");
            }
            else
            {
                Console.WriteLine("Bu sayilar arkadas sayi degildir");
            }
        }
    }
}
