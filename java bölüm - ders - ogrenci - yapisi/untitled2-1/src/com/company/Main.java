package com.company;

import java.util.Scanner;

public class Main {



    public static void main(String[] args) {
	// write your code here

        Grade_Calculate gradeCalculate = new Grade_Calculate() {
            @Override
            public int grade_calculator(int mid1weight, int mid1point, int mid2weight, int mid2point, int finalweight, int finalpoint) {
                int finalresult = ((mid1point * mid1weight) + (mid2point * mid2weight) + (finalpoint * finalweight))/100;

                return finalresult;
            }
        };

        //System.out.println(gradeCalculate.grade_calculator(20,60,20,60,60, 70));


        University university = new University();

        Student osman = new Student("osman","gultekin",22, "erkek", "abc", "cs", 2021);

        ClassExample osman101 = new ClassExample("cs101", "finished", 50,50,50);
        ClassExample osman201 = new ClassExample("cs201", "finished", 60,60,60);



        osman.getCourse_list().courses.add(osman101);
        osman.getCourse_list().courses.add(osman201);

        Student aykut = new Student("aykut","elmas",22, "erkek", "abc", "cs", 2022);

        ClassExample aykut101 = new ClassExample("cs201", "finished", 60,60,60);
        ClassExample aykut201 = new ClassExample("cs301", "finished", 70,70,70);

        aykut.getCourse_list().courses.add(aykut101);
        aykut.getCourse_list().courses.add(aykut201);

        Student cagri = new Student("cagri","han",4, "erkek", "abc", "cs", 2022);

        ClassExample cagri101 = new ClassExample("cs101", "finished", 90,90,90);
        ClassExample cagri201 = new ClassExample("cs201", "finished", 45,75,90);
        ClassExample cagri301 = new ClassExample("cs301", "finished", 40,80,90);

        cagri.getCourse_list().courses.add(cagri101);
        cagri.getCourse_list().courses.add(cagri201);
        cagri.getCourse_list().courses.add(cagri301);









    }
}
