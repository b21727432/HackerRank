package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    List<Ogrenci> ogrenciler = new ArrayList<Ogrenci>();

	    ogrenciBilgileriEkle(ogrenciler);
        ogrenciBilgileriEkle(ogrenciler);
        ogrenciBilgileriEkle(ogrenciler);

        ortalamaUstuOgrenciAdlariListele(ogrenciler);

        System.out.println(vize1Ortalama(ogrenciler));

        System.out.println(vize1StandartSapma(ogrenciler));

        genelHarfNotuBelirle(ogrenciler);
    }

    public static void ogrenciBilgileriEkle(List<Ogrenci> ogrenciler){
        Scanner myObj = new Scanner(System.in);

        System.out.println("Sırayla ogrenci adi cinsiyeti vize1 ve vize2 notunu giriniz :");
        String isim = myObj.nextLine();
        String cinsiyet = myObj.nextLine();
        int vize1 = myObj.nextInt();
        int vize2 = myObj.nextInt();

        Ogrenci ogrenci = new Ogrenci(isim, cinsiyet, vize1, vize2);

        ogrenciler.add(ogrenci);
    }

    public static void ortalamaUstuOgrenciAdlariListele(List<Ogrenci> ogrenciler){
        double viz1ort = 0, viz2ort = 0;
        for(int i = 0; i < ogrenciler.size(); i++){
            viz1ort += ogrenciler.get(i).vize1;
            viz2ort += ogrenciler.get(i).vize2;
        }
        viz1ort = viz1ort / ogrenciler.size();
        viz2ort = viz2ort / ogrenciler.size();

        for(int i = 0; i < ogrenciler.size(); i++){
            if(ogrenciler.get(i).vize1 > viz1ort && ogrenciler.get(i).vize2 > viz2ort){
                System.out.println(ogrenciler.get(i).ad);
            }
        }
    }

    public static double vize1Ortalama(List<Ogrenci> ogrenciler){
        double viz1ort = 0;
        for(int i = 0; i < ogrenciler.size(); i++){
            viz1ort += ogrenciler.get(i).vize1;
        }
        viz1ort = viz1ort / ogrenciler.size();

        return viz1ort;
    }

    public static double vize1StandartSapma(List<Ogrenci> ogrenciler){
        double viz1ort = vize1Ortalama(ogrenciler);
        double karefark = 0;
        for(int i = 0; i < ogrenciler.size(); i++){
            double x = ogrenciler.get(i).vize1 - viz1ort;
            x = x * x;
            karefark += x;
        }
        karefark = karefark / (ogrenciler.size() - 1);
        karefark = Math.sqrt(karefark);

        return karefark;
    }

    public static void genelHarfNotuBelirle(List<Ogrenci> ogrenciler){

        for(int i = 0; i < ogrenciler.size(); i++){
            double genelnot = (ogrenciler.get(i).vize1 * 30 / 100) + (ogrenciler.get(i).vize2 * 70 / 100);
            if(genelnot >= 85){
                System.out.println(ogrenciler.get(i).ad + " adlı ogrencinin gecme notu : " + genelnot + " harf notu : " + "AA");
            }
            else if(genelnot >= 80 && genelnot <= 84){
                System.out.println(ogrenciler.get(i).ad + " adlı ogrencinin gecme notu : " + genelnot + " harf notu : " + "BA");
            }
            else if(genelnot >= 75 && genelnot <= 79){
                System.out.println(ogrenciler.get(i).ad + " adlı ogrencinin gecme notu : " + genelnot + " harf notu : " + "BB");
            }
            else if(genelnot >= 70 && genelnot <= 74){
                System.out.println(ogrenciler.get(i).ad + " adlı ogrencinin gecme notu : " + genelnot + " harf notu : " + "CB");
            }
            else if(genelnot >= 65 && genelnot <= 69){
                System.out.println(ogrenciler.get(i).ad + " adlı ogrencinin gecme notu : " + genelnot + " harf notu : " + "CC");
            }
            else if(genelnot >= 60 && genelnot <= 64){
                System.out.println(ogrenciler.get(i).ad + " adlı ogrencinin gecme notu : " + genelnot + " harf notu : " + "DC");
            }
            else if(genelnot >= 50 && genelnot <= 59){
                System.out.println(ogrenciler.get(i).ad + " adlı ogrencinin gecme notu : " + genelnot + " harf notu : " + "DD");
            }
            else{
                System.out.println(ogrenciler.get(i).ad + " adlı ogrencinin gecme notu : " + genelnot + " harf notu : " + "FF");
            }

        }
    }
}
