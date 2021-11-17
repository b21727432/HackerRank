using System;

namespace ConsoleApp11
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Gec Getirilen Kitap Sayisi :");
            int kitapsayisi = Convert.ToInt32(Console.ReadLine());
            Console.Write("Gecikme Gun Sayisi :");
            int gunsayisi = Convert.ToInt32(Console.ReadLine());
            Console.Write("Bir gunluk gecikme cezasi :");
            int ceza = Convert.ToInt32(Console.ReadLine());
            double toplam_ceza = 0;
            if(gunsayisi <= 5)
            {
                toplam_ceza = gunsayisi * ceza; 
            } else if(gunsayisi >= 6 && gunsayisi <= 10)
            {
                toplam_ceza = 5 * ceza + (gunsayisi - 5) * (ceza * 110.0 / 100.0);
            }
            else
            {
                toplam_ceza = 5 * ceza + (10 - 5) * (ceza * 110 / 100) + (gunsayisi - 10) * (ceza * 125.0 / 100.0);
            }
            Console.WriteLine("Toplam odeyeceginiz gec getirme borcunuz : " + toplam_ceza);
        }
    }
}
