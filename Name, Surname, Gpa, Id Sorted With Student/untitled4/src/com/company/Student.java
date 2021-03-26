package com.company;

public class Student {
    private String ID;
    private String name;
    private String surname;
    private double mt1;
    private double mt2;
    private double fin;

    public Student(String ID, String name, String surname, double mt1, double mt2, double fin) {
        this.ID = ID;
        this.name = name;
        this.surname = surname;
        this.mt1 = mt1;
        this.mt2 = mt2;
        this.fin = fin;
    }

    public double CalculateGPA(){
        double GPA = ((this.getMt1() + this.getMt2())/2) * 40 / 100 + this.getFin() * 60 / 100;
        return GPA;
    }

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public double getMt1() {
        return mt1;
    }

    public void setMt1(double mt1) {
        this.mt1 = mt1;
    }

    public double getMt2() {
        return mt2;
    }

    public void setMt2(double mt2) {
        this.mt2 = mt2;
    }

    public double getFin() {
        return fin;
    }

    public void setFin(double fin) {
        this.fin = fin;
    }
}
