using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp7
{
    class meyve
    {
        public string isim;
        public int sepet;
        public meyve()
        {
            isim = "elma";
            sepet = 5;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            meyve nesne = new meyve();
            Console.WriteLine(nesne.sepet + " sepet " + nesne.isim);
            Console.ReadLine();
        }
    }
}
