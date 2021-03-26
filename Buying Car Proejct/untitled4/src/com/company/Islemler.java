package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Islemler {

    public ArrayList<Araba> arabalar = new ArrayList<Araba>(30);
    // String plaka, Kisi sahip, int uretimYili, String durum, String renk, String marka
    public void arabaVerileriEkle(){
        Scanner myObj = new Scanner(System.in);

        System.out.println("Araba bilgilerini aralarında enter olucak sekilde girin(plaka, isim, cinsiyet, yas, uretimyili, durum, renk, marka) : ");
        String plaka = myObj.nextLine();
        String isim = myObj.nextLine();
        String cinsiyet = myObj.nextLine();
        int yas = myObj.nextInt();
        myObj.nextLine();
        int uretimYili = myObj.nextInt();
        myObj.nextLine();
        String durum = myObj.nextLine();
        String renk = myObj.nextLine();
        String marka = myObj.nextLine();

        Kisi kisi = new Kisi(isim, cinsiyet, yas);

        Araba araba = new Araba(plaka, kisi, uretimYili, durum, renk, marka);

        arabalar.add(araba);

        System.out.println("Araba eklendi...");
    }

    public void plakaKontrol(){
        Scanner myObj = new Scanner(System.in);

        System.out.println("Aramak istediginiz plakayi giriniz : ");
        String plaka = myObj.nextLine();

        for(int i = 0; i < arabalar.size(); i++){
            if(arabalar.get(i).getPlaka() == plaka){
                System.out.println("Ayni plakali arac bulunmustur...");
            }
        }
    }

    public void baybayanyuzde(){
        int erkek = 0, kadin = 0;
        for(int i = 0 ; i < arabalar.size(); i++){
            if(arabalar.get(i).getSahip().cinsiyet == "erkek"){
                erkek += 1;
            }
            else{
                kadin += 1;
            }
        }

        System.out.println("Erkek yuzdesi : " + ((erkek / (erkek + kadin)) * 100));
        System.out.println("Kadin yuzdesi : " + ((kadin / (kadin + erkek)) * 100));
    }

    public void arabaBilgileriniListele(){

        for(int i = 0; i < arabalar.size(); i++){
            System.out.println("Araba plakası : " + arabalar.get(i).getPlaka() + " Araba Sahibi Bilgileri : " + arabalar.get(i).getSahip().isim + " " + arabalar.get(i).getSahip().cinsiyet + " " + arabalar.get(i).getSahip().yas + " Araba uretim yili : " + arabalar.get(i).getUretimYili() + " Araba Durumu : " + arabalar.get(i).getDurum() + " Araba Rengi : " + arabalar.get(i).getRenk() + " Araba Markasi : " + arabalar.get(i).getMarka());
        }

    }
}
