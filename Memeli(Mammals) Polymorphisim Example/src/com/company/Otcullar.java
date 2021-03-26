package com.company;

public class Otcullar extends  HayvanlarClass implements Otcul{

    private String favoriot;


    public Otcullar(String name) {
        super(name);
    }

    public Otcullar(String name, int age) {
        super(name, age);
    }

    public Otcullar(String name, int age, String favoriot){
        super(name,age);
        this.favoriot = favoriot;
    }


    @Override
    public void yayil() {
        System.out.println("ben : " + this.getName() + "ot arıyorum");
    }

    @Override
    public void kac() {
        System.out.println("ben : " + this.getName() + "etcil kovalıyor kacıyorum");
    }

    @Override
    public void otYe() {
        System.out.println("ben : " + this.getName() + "ot yiyorum");
    }

    @Override
    public void havasolu() {
        System.out.println("ben : " + this.getName() + "ohhh oksijen");
    }

    @Override
    public void ye() {
        System.out.println("ben : " + this.getName() + "ot yiyorum");
    }

    @Override
    public void konus() {
        System.out.println("ben : " + this.getName() + "ben bir otculum");
    }

    @Override
    public void hareketet() {
        System.out.println("ben : " + this.getName() + "yürüyorum");
    }
}
