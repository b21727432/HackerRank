using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sınav
{
    class Program
    {
        static void Main(string[] args)
        {
            new kitap();
            new kitap(255);
            new kitap(123, "mavi");
            Console.ReadLine();
        }
    }

    class kitap
    {
        int sayfaSayisi = 600;
        string renk = "siyah";

        public kitap()
        {
            Console.WriteLine(renk + " renkli " + sayfaSayisi + " sayfali kitap.");
        }
        public kitap(int yenisayfaSayisi)
        {
            sayfaSayisi = yenisayfaSayisi;
            Console.WriteLine(renk + " renkli " + sayfaSayisi + " sayfali kitap.");
        }

        public kitap(int yenisayfaSayisi, string yenirenk)
        {
            sayfaSayisi = yenisayfaSayisi;
            renk = yenirenk;
            Console.WriteLine(renk + " renkli " + sayfaSayisi + " sayfali kitap.");
        }

    }
}
