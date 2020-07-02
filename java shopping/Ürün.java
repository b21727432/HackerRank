package com.company;

public class Ürün {
    String isim;
    int fiyat;

    public Ürün(String isim, int fiyat) {
        this.isim = isim;
        this.fiyat = fiyat;
    }

    @Override
    public String toString() {
        return "Ürün{" +
                "isim='" + isim + '\'' +
                ", fiyat=" + fiyat +
                '}';
    }
}
