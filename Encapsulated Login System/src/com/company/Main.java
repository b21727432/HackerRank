package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
	// write your code here
        EncapsulatedUser encapsulatedUser = new EncapsulatedUser("user112233", "123456789");
        encapsulatedUser.setPassword();
        encapsulatedUser.getName();

        EncapsulatedUser user1 = new EncapsulatedUser("user11","123456", "x");
        EncapsulatedUser user2 = new EncapsulatedUser("user22","1234567", "y");
        EncapsulatedUser user3 = new EncapsulatedUser("user33","1234568", "z");
        EncapsulatedUser user4 = new EncapsulatedUser("user44","123456789", "t");

        List<EncapsulatedUser> users = new ArrayList<EncapsulatedUser>();

        users.add(user1);
        users.add(user2);
        users.add(user3);
        users.add(user4);
        Platform platform = new Platform("konser", users);

        platform.allUsers();
    }
}
