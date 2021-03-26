package com.company;

public class Course {

    private String name;
    private int grade;
    private String status;
    private Calculator grade_calculator;

    public void calculateGrade(int mid1weight,int mid1point, int mid2weight, int mid2point, int finalweight, int finalpoint){
        if(this.status.equals("registered")){
            System.out.println("No grade can be calculated for this course");
        }
        else{
            this.grade = this.grade_calculator.grade_calculator(mid1weight, mid1point, mid2weight, mid2point, finalweight, finalpoint);
            if(this.grade > 60){
                this.status = "passed";
            }
            else{
                this.status = "failed";
            }
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getGrade() {
        return grade;
    }

    public void setGrade(int grade) {
        this.grade = grade;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public Calculator getGrade_calculator() {
        return grade_calculator;
    }

    public void setGrade_calculator(Calculator grade_calculator) {
        this.grade_calculator = grade_calculator;
    }
}
