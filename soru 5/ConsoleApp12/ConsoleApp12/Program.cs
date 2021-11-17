using System;

namespace ConsoleApp12
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Mukemmel sayi kontrolu yapilicak sayiyi giriniz:");
            int sayi = Convert.ToInt32(Console.ReadLine());
            int bolen_toplam = 0;
            for(int i = 1; i < sayi; i++)
            {
                if(sayi % i == 0)
                {
                    bolen_toplam += i;
                }
            }
            if(bolen_toplam == sayi)
            {
                Console.WriteLine("Girdiginiz Sayi Mukemmel Sayidir.");
            }
            else
            {
                Console.WriteLine("Girdiginiz Sayi Mukemmel Sayi Degildir.");
            }
        }
    }
}
