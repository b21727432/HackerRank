using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class Program
    {
        static void Main(string[] args)
        {
            birSınıf nesne1 = new birSınıf();
            birSınıf nesne2 = new birSınıf();
            birSınıf nesne3 = new birSınıf();
            Console.WriteLine(nesne1.i);
            Console.WriteLine(nesne2.j);
            Console.WriteLine(nesne3.karekök());
            Console.ReadLine();
        }
    }
    class birSınıf
    {
        public int i = 10;
        public int j = 18;
        public double karekök()
        {
            return Math.Sqrt(10);
        }
    }
}
