using System;
using System.IO;

namespace ConsoleApp10
{
    class Ogrenci
    {
        public string isim;
        public string soyisim;
        public int vize;
        public int final;
        public double ort;
        public void ortalama_hesapla()
        {
            this.ort = vize * 40.0 / 100.0 + final * 60.0 / 100.0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Ogrenci[] ogrenciler = new Ogrenci[15];
            for(int i = 0; i < 15; i++)
            {
                ogrenciler[i] = new Ogrenci();
            }
            int ogrenci_sayisi = 0;
            string[] lines = File.ReadAllLines(@"C:\\Users\\grupofis\\\Desktop\\veriler.txt");
            foreach(string line in lines)
            {
                string[] kelimeler = line.Split(",");
                ogrenciler[ogrenci_sayisi].isim = kelimeler[0];
                ogrenciler[ogrenci_sayisi].soyisim = kelimeler[1];
                ogrenciler[ogrenci_sayisi].vize = Int32.Parse(kelimeler[2]);
                ogrenciler[ogrenci_sayisi].final = Int32.Parse(kelimeler[3]);
                ogrenciler[ogrenci_sayisi].ortalama_hesapla();
                ogrenci_sayisi++;
            }
            int kalan_sayisi = 0;
            double kalanlarin_ort = 0;
            Console.WriteLine("Gecen Ogrencilerin Adi Soyadlari :");
            for(int i = 0; i < 15; i++)
            {
                if(ogrenciler[i].ort >= 50)
                {
                    Console.WriteLine("Adi : " + ogrenciler[i].isim + " Soyadi : " + ogrenciler[i].soyisim + " Vize Notu : " + ogrenciler[i].vize + " Final Notu : " + ogrenciler[i].final + " Ortalamasi : " + ogrenciler[i].ort);
                }
                else
                {
                    kalanlarin_ort += ogrenciler[i].ort;
                    kalan_sayisi++;
                }
            }
            Console.WriteLine("Dersten kalan ogrencilerin sayisi : " + kalan_sayisi + " Kalan ogrencilerin ortalamasi : " + kalanlarin_ort / kalan_sayisi);
            Console.WriteLine("Final Notu Vize Notundan Buyuk Olan Ogrenciler :");
            for(int i = 0; i < 15; i++)
            {
                if(ogrenciler[i].final > ogrenciler[i].vize)
                {
                    Console.WriteLine("Final Notu Vize Notundan Buyuk Olan Ogrencinin Adi : " + ogrenciler[i].isim + " Soyadi : " + ogrenciler[i].soyisim + " Vize Notu : " + ogrenciler[i].vize + " Final Notu : " + ogrenciler[i].final + " Ortalamasi : " + ogrenciler[i].ort);
                }
            }
        }
    }
}
