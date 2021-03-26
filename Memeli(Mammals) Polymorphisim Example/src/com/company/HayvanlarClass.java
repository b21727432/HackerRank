package com.company;

public abstract class HayvanlarClass implements Hayvanlar{

    private String name;
    private int age;

    public HayvanlarClass(String name) {
        this.name = name;
    }

    public HayvanlarClass(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public void ye() {
        System.out.println("hayvanlar yemek yer");
    }

    @Override
    public void konus() {
        System.out.println("ben bir hayvanım");
    }

    @Override
    public void hareketet() {
        System.out.println("hayvanlar hareket eder");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
