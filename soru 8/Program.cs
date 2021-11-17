using System;
using System.Linq;

namespace ConsoleApp20
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            
            int[] sayilar = new int[5];
            for (int i = 0; i < 5; i++)
            {
                int x = rnd.Next(1, 34);
                while (sayilar.Contains(x))
                {
                    x = rnd.Next(1, 34);
                }
                sayilar[i] = x;               
            }
            
            int joker = rnd.Next(1, 14);

            int[] kullanici_rakamlar = new int[5];
            int kullanici_joker;
            Console.WriteLine("Sectiginiz Rakamları Giriniz :");
            for(int i = 0; i < 5; i++)
            {
                Console.Write(i + 1 + ". numaranizi giriniz: ");
                kullanici_rakamlar[i] = Convert.ToInt32(Console.ReadLine());
            }
            Console.Write("Joker numaranizi giriniz: ");
            kullanici_joker = Convert.ToInt32(Console.ReadLine());
            int kullanici_dogru = 0;
            for(int i = 0; i < 5; i++)
            {
                if (sayilar.Contains(kullanici_rakamlar[i]))
                {
                    kullanici_dogru++;
                }
            }
            if(joker == kullanici_joker)
            {
                if(kullanici_dogru != 0)
                {
                    Console.WriteLine("Tebrikler " + kullanici_dogru + "+1 sayi bildiniz.Odul Kazandiniz");
                }
                else
                {
                    Console.WriteLine("Malesef Odul Kazanamadiniz.");
                }
            }
            else
            {
                if(kullanici_dogru == 3 || kullanici_dogru == 4 || kullanici_dogru == 5)
                {
                    Console.WriteLine("Tebrikler " + kullanici_dogru + " sayi bildiniz.Odul Kazandınız.");
                }
                else
                {
                    Console.WriteLine("Malesef odul kazanamadınız");
                }
                
            }

        }
    }
}
