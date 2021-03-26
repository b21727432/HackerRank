package com.company;

import java.util.List;

public class Platform {
    public String name;
    public List<EncapsulatedUser> users;

    public Platform(String name, List<EncapsulatedUser> users) {
        this.name = name;
        this.users = users;
    }

    public void allUsers(){
        System.out.println("Printing all users...");
        for(int i = 0; i < this.users.size() ; i++){
            String name = this.users.get(i).getName();
            if(name.equals("name is wrong")){
                System.out.println("wrong name, cant access");
            }
            else{
                System.out.println("Name : " + name + " Password : " + this.users.get(i).getPassword() + " Location : " + this.users.get(i).getLocation());
            }
        }
    }
}
