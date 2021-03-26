package com.company;

import java.util.Scanner;

public class EncapsulatedUser {

    static int numberOfInstances = 0;

    {
        numberOfInstances += 1;
    }

    private String name;
    private String password;
    private String location;

    public EncapsulatedUser(String name, String password) {
        this.name = name;
        this.password = password;
    }

    public EncapsulatedUser(String name, String password, String location) {
        this.name = name;
        this.password = password;
        this.location = location;
    }

    public String getName() {

        Scanner myObj = new Scanner(System.in);
        System.out.println("Enter your name");
        String name = myObj.nextLine();

        if(name.equals(this.name)){
            return name;
        }
        else{
            return "name is wrong";
        }


    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword() {

        Scanner myObj = new Scanner(System.in);

        int count = 9;
        while(count > 0){
            System.out.println("Enter current password");
            String oldpassword = myObj.nextLine();

            if(this.password != password){
                System.out.println("Wrong Password "+count+" Number of tries left.Write again :");
                continue;
            }
            else{
                this.password = password;
                System.out.println("Password has changed.");
                break;
            }
        }
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }
}
