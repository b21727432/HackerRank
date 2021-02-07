using System;
using System.IO;
using System.Linq;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Dosya Dizinini Giriniz :");
            string adres = Console.ReadLine();
            adres = adres + "\\c.txt";
            Console.WriteLine("Kac Cumle Ekleyeceksiniz? :");
            int cumlesayisi = Convert.ToInt32(Console.ReadLine());

            using (var sw = new StreamWriter(adres))
            {
                for (var i = 0; i < cumlesayisi; i++)
                {
                    Console.WriteLine("Cumleyi Giriniz :");
                    string cumle = Console.ReadLine();
                    sw.WriteLine(cumle);
                }
            }

            string text = File.ReadAllText(adres);
            Console.WriteLine(text);
            Console.WriteLine("Aramak istediginiz kelimeyi giriniz :");


            string aranan = Console.ReadLine();
            string[] source = text.Split(new char[] { '.', '?', '!', ' ', ';', ':', ',' , '\n'}, StringSplitOptions.RemoveEmptyEntries);
            var matchQuery = from word in source
                             where word.ToLowerInvariant() == aranan.ToLowerInvariant()
                             select word;
             int wordCount = matchQuery.Count();
            Console.WriteLine("{0} adet \"{1}\" kelimesi bulundu.", wordCount, aranan);
        }
    }
}
