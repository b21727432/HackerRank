package com.company;

public class Araba {

    private String plaka;
    private Kisi sahip;
    private int uretimYili;
    private String durum;
    private String renk;
    private String marka;

    public Araba(String plaka, Kisi sahip, int uretimYili, String durum, String renk, String marka) {
        this.plaka = plaka;
        this.sahip = sahip;
        this.uretimYili = uretimYili;
        this.durum = durum;
        this.renk = renk;
        this.marka = marka;
    }

    public String getPlaka() {
        return plaka;
    }

    public void setPlaka(String plaka) {
        this.plaka = plaka;
    }

    public Kisi getSahip() {
        return sahip;
    }

    public void setSahip(Kisi sahip) {
        this.sahip = sahip;
    }

    public int getUretimYili() {
        return uretimYili;
    }

    public void setUretimYili(int uretimYili) {
        this.uretimYili = uretimYili;
    }

    public String getDurum() {
        return durum;
    }

    public void setDurum(String durum) {
        this.durum = durum;
    }

    public String getRenk() {
        return renk;
    }

    public void setRenk(String renk) {
        this.renk = renk;
    }

    public String getMarka() {
        return marka;
    }

    public void setMarka(String marka) {
        this.marka = marka;
    }
}
