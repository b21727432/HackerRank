package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        ClassList a = new ClassList();
        Scanner myObj = new Scanner(System.in);
        while(true){
            System.out.println("1. Add student to the list\n2. Print the Class List\n3. Exit");
            System.out.print("Enter your choice: ");
            int x = myObj.nextInt();
            myObj.nextLine();
            if(x == 1){
                System.out.println("Name: ");
                String name = myObj.nextLine();
                System.out.println("Surname: ");
                String surname = myObj.nextLine();
                System.out.println("ID: ");
                String ID = myObj.nextLine();
                System.out.println("Midterm1: ");
                double mid1 = myObj.nextDouble();
                myObj.nextLine();
                System.out.println("Midterm2: ");

                double mid2 = myObj.nextDouble();
                myObj.nextLine();
                System.out.println("Final: ");

                double fin = myObj.nextDouble();
                myObj.nextLine();
                a.Add(new Student(ID, name, surname, mid1, mid2, fin));

            }
            else if(x == 2){
                System.out.println("Select how you sorted\n0. Sorted by GPA\n1. Sorted By ID\n2. Sorted by Name\n3. Sorted by Surname");
                int y = myObj.nextInt();
                if(y == 0){
                    a.PrintSortedList(y);
                }
                else if(y == 1){
                    a.PrintSortedList(y);
                }
                else if(y == 2){
                    a.PrintSortedList(y);
                }
                else if(y == 3){
                    a.PrintSortedList(y);
                }
            }
            else if(x == 3){
                System.out.println("Goodbye!");
                break;
            }

        }

    }
}
