package com.company;

public class Course {

    private String name;
    private String grade;
    private String status;
    public Grade_Calculate grade_calculator;

    public int calculateGrade(int mid1weight,int mid1point, int mid2weight, int mid2point, int finalweight, int finalpoint){
        int finalresult;
        if(this.status.equals("registered")){
            System.out.println("No grade can be calculated for this course");
            return 0;
        }
        else{
            finalresult  = ((mid1point * mid1weight) + (mid2point * mid2weight) + (finalpoint * finalweight))/100;
            if(finalresult > 60){
                this.setStatus("passed");
                System.out.println(getStatus());
                System.out.println(finalresult);
            }
            else{
                this.setStatus("failed");
                System.out.println(getStatus());
                System.out.println(finalresult);
            }

        }
        return finalresult;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getGrade() {
        return grade;
    }

    public void setGrade(String grade) {
        this.grade = grade;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }



    public Course(String name, String status) {
        this.name = name;
        this.status = status;
    }
}
