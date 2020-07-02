package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);


        Kullanıcı kullanıcı1 = new Kullanıcı("osman", "sasi", "Sivas");
        Kullanıcı kullanıcı2 = new Kullanıcı("hatice", "sasmaz", "Igdır");
        Kullanıcı kullanıcı3 = new Kullanıcı("mert", "korkut", "Ağrı");

        Ürün ürün1 = new Ürün("1984",25);
        Ürün ürün2 = new Ürün("Kavgam",1);
        Ürün ürün3 = new Ürün("Suç ve Ceza",10);
        Ürün ürün4 = new Ürün("Jane Eyre",5);
        Ürün ürün5 = new Ürün("Tula Teyze",15);

        List<Ürün> ürünList = new ArrayList<>();
        ürünList.add(ürün1);
        ürünList.add(ürün2);
        ürünList.add(ürün3);
        ürünList.add(ürün4);
        ürünList.add(ürün5);



        while(true){
            System.out.println("Alışveriş Sistemine Hoşgeldiniz...");
            System.out.println("Bir kullanıcı seçiniz : (Çıkış için -1 yazınız)");
            System.out.println("1 ) " + kullanıcı1.ad + " " + kullanıcı1.soyad + " "+ kullanıcı1.adres);
            System.out.println("2 ) " + kullanıcı2.ad + " "+ kullanıcı2.soyad + " "+ kullanıcı2.adres);
            System.out.println("3 ) " + kullanıcı3.ad + " "+ kullanıcı3.soyad + " "+ kullanıcı3.adres);

            int secim = input.nextInt();

            if(secim == 1){
                System.out.println("Sisteme " + kullanıcı1.ad + " "+ kullanıcı1.soyad + " "+ kullanıcı1.adres + " ile giriş yapıldı.Ürünler Hazırlanıyor...");
            }
            else if(secim == 2){
                System.out.println("Sisteme " + kullanıcı2.ad + " "+ kullanıcı2.soyad + " "+ kullanıcı2.adres + " ile giriş yapıldı.Ürünler Hazırlanıyor...");
            }
            else if(secim == 3){
                System.out.println("Sisteme " + kullanıcı3.ad + " "+ kullanıcı3.soyad + " "+ kullanıcı3.adres + " ile giriş yapıldı.Ürünler Hazırlanıyor...");
            }
            else{
                System.out.println("Sistemden çıkılıyor...İyi Günler...");
                break;
            }

            Sepet sepet = new Sepet();

            sepet.ürün = new ArrayList<>();
            sepet.adet = new ArrayList<>();



        while(true){
            System.out.println("1 ) Ürünleri Görüntüle ");
            System.out.println("2 ) Sepeti Görüntüle ");
            int secim2 = input.nextInt();
            if(secim2 == 1){

                while(true){
                    for(int i = 0; i < ürünList.size(); i++){
                        System.out.println(i+1 + ") " + "Ürün İsmi : " + ürünList.get(i).isim + " , Ürün Fiyatı : " + ürünList.get(i).fiyat);
                    }
                    System.out.println("Almak istediğiniz ürünü ve sonrasında adetini giriniz, Çıkmak için -1 yazınız ...");
                    int secim3 = input.nextInt();
                    if(secim3 == -1){
                        System.out.println("Ana ekrana dönülüyor, Ürünler için 1, Sepeti Görüntülemek İçin 2 yazınız...");
                        break;
                    }
                    System.out.println("Ürün adetini giriniz...");
                    int adet = input.nextInt();
                    sepet.ürün.add(ürünList.get(secim3 - 1));
                    sepet.adet.add(adet);
                }
            }
            else if(secim2 == 2){

                System.out.println("Sepetteki Ürünler : ");
                for(int i = 0; i < sepet.ürün.size(); i++){
                    System.out.println(i+1 + ") " + "Ürün İsmi : " + sepet.ürün.get(i).isim+ " , Ürün Fiyatı : " + sepet.ürün.get(i).fiyat + " , Ürün Adedi : " + sepet.adet.get(i));
                }
                System.out.println("Sepetinizden istediğiniz ürünü çıkarmak için ürünün numarasını giriniz, ana ekran için -1'e, sepetinizi onaylamak için 0'a basınız...");
                int secim4 = input.nextInt();
                if(secim4 == -1){
                    continue;
                }
                else if(secim4 == 0){
                    System.out.println("Siparişiniz adresinize gönderildi...");
                    sepet = null;
                    break;
                }
                else {
                    System.out.println("Seçtiğiniz ürün sepetinizden siliniyor ...");
                    sepet.ürün.remove(secim4-1);
                    sepet.adet.remove(secim4-1);
                }

            }
        }
        }

    }
}
