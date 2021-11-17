using System;

namespace ConsoleApp16
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Cekilicek Miktar Giriniz : ");
            double miktar = Convert.ToDouble(Console.ReadLine());
            Console.Write("Vade Tarihi Giriniz : ");
            double vade = Convert.ToDouble(Console.ReadLine());
            Console.Write("Kredi Turunu Giriniz : ");
            string tur = Console.ReadLine();
            double faiz, odeme = 0;
            if(tur == "Konut Kredisi")
            {
                faiz = 1.08;
                odeme = (miktar * faiz / 100) / (1.0 - (1.0 / (Math.Pow((1.0 + faiz/100), vade))));
                Console.WriteLine("Aylik Odeme Miktari : " + odeme.ToString("0.00000") + " Toplam Odenecek Miktar : " + (odeme*vade).ToString("0.00000") );
            } else if(tur == "Tasit Kredisi")
            {
                faiz = 1.25;
                odeme = (miktar * faiz / 100) / (1.0 - (1.0 / (Math.Pow((1.0 + faiz / 100), vade))));
                Console.WriteLine("Aylik Odeme Miktari : " + odeme.ToString("0.00000") + " Toplam Odenecek Miktar : " + (odeme * vade).ToString("0.00000"));
            }
            else
            {
                Console.WriteLine("Duzgun bir kredi turu girmediniz..");
            }
        }
    }
}
