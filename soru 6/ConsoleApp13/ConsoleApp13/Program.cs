using System;

namespace ConsoleApp13
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Kisi sayisini giriniz:");
            int kisi = Convert.ToInt32(Console.ReadLine());
            int tokalasma = 0;
            for(int i = kisi; i > 1; i--)
            {
                tokalasma += i - 1;
            }
            Console.WriteLine("Toplam Tokalasma Sayisi : " + tokalasma);
        }
    }
}
