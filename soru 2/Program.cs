using System;

namespace ConsoleApp15
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("A noktasi x koordinatini giriniz : ");
            int ax = Convert.ToInt32(Console.ReadLine());
            Console.Write("A noktasi y koordinatini giriniz : ");
            int ay = Convert.ToInt32(Console.ReadLine());
            Console.Write("B noktasi x koordinatini giriniz : ");
            int bx = Convert.ToInt32(Console.ReadLine());
            Console.Write("B noktasi y koordinatini giriniz : ");
            int by = Convert.ToInt32(Console.ReadLine());
            if(bx == ax)
            {
                Console.Write("Dogrunun Egimi Sonsuzdur.");
            } else if(by == ay)
            {
                Console.Write("Dogrunun Egimi Sifirdir.");
            }
            else
            {
                double egim = (by - ay) / (bx - ax);
                Console.Write("Dogrunun Egimi : " + egim);
            }
            
        }
    }
}
