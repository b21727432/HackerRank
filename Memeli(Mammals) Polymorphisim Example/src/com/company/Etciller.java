package com.company;

public class Etciller extends  HayvanlarClass implements Etcil{

    private String favoriet;

    public Etciller(String name) {
        super(name);
    }

    public Etciller(String name, int age) {
        super(name, age);
    }

    public Etciller(String name, int age, String favoriet){
        super(name,age);
        this.favoriet = favoriet;
    }

    @Override
    public void avlan() {
        System.out.println("ben : " + this.getName() + "avlanıyorum");
    }

    @Override
    public void pus() {
        System.out.println("ben : " + this.getName() + "pustum bekliyorum");
    }

    @Override
    public void etYe() {
        System.out.println("ben : " + this.getName() + "et yiyorum");
    }

    @Override
    public void havasolu() {
        System.out.println("ben : " + this.getName() + "ohhh oksijen");
    }

    @Override
    public void ye() {
        System.out.println("ben : " + this.getName() + "et yiyorum");
    }

    @Override
    public void konus() {
        System.out.println("ben : " + this.getName() + "ben bir etcilim");
    }

    @Override
    public void hareketet() {
        System.out.println("ben : " + this.getName() + "yürüyorum");
    }

    public String getFavoriet() {
        return favoriet;
    }

    public void setFavoriet(String favoriet) {
        this.favoriet = favoriet;
    }
}
