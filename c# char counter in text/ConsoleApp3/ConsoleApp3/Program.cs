using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            // C:\Users\grupofis\Desktop
            Console.WriteLine("Dosyanin adresini giriniz :");
            string adres = Console.ReadLine();
            if (File.Exists(adres))
            {
                string text = File.ReadAllText(adres);
                //Console.WriteLine(text);

                var harfSozluk = new Dictionary<char, int>();
                string yazma = "";
                foreach(char seciliHarf in text)
                {
                    if (harfSozluk.ContainsKey(seciliHarf))
                    {
                        harfSozluk[seciliHarf]++;
                    }
                    else
                    {
                        harfSozluk.Add(seciliHarf, 1);
                    }
                }

                foreach(char seciliHarf in harfSozluk.Keys)
                {
                    Console.Write(seciliHarf + "(" + harfSozluk[seciliHarf] + ") ");
                    yazma += seciliHarf + "(" + harfSozluk[seciliHarf] + ") ";
                    
                }
                Console.WriteLine("\nYazilicak Dosyanin adresini giriniz :");
                string ciktiadres = Console.ReadLine();
                File.WriteAllText(@ciktiadres, yazma);

                Console.ReadLine();
            }
        }
    }
}
