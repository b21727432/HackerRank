using System;
using System.Linq;

namespace ConsoleApp21
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();

            int[] on_numara = new int[22];
            for(int i = 0; i < 22; i++)
            {
                int x = rnd.Next(1, 80);
                while (on_numara.Contains(x))
                {
                    x = rnd.Next(1, 80);
                }
                on_numara[i] = x;
            }

            int[] kullanici_secim = new int[10];
            Console.WriteLine("Seçtiğiniz rakamları giriniz:");
            for(int i = 0; i < 10; i++)
            {
                Console.Write(i + 1 + ". Numaranızı giriniz:");
                kullanici_secim[i] = Convert.ToInt32(Console.ReadLine());
            }
            int kullanici_dogru = 0;
            for(int i = 0; i < 10; i++)
            {
                if (on_numara.Contains(kullanici_secim[i]))
                {
                    kullanici_dogru++;
                }
            }

            if(kullanici_dogru == 0 || kullanici_dogru == 6 || kullanici_dogru == 7 || kullanici_dogru == 8 || kullanici_dogru == 9 || kullanici_dogru == 10)
            {
                Console.WriteLine("Tebrikler " + kullanici_dogru + " Dogru Tahmin ile ödül kazandınız.");
            }
            else
            {
                Console.WriteLine("Malesef Odul kazanamadınız.");
            }

        }
    }
}
