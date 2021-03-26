package com.company;

public class Student extends Person{

    private String university;
    private String department;
    private Integer year;
    private Course_List course_list;

    public String getUniversity() {
        return university;
    }

    public void setUniversity(String university) {
        this.university = university;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public Integer getYear() {
        return year;
    }

    public void setYear(Integer year) {
        this.year = year;
    }

    public Course_List getCourse_list() {
        return course_list;
    }

    public void setCourse_list(Course_List course_list) {
        this.course_list = course_list;
    }

    public Student(String name, String surname, Integer age, String gender, String university, String department, Integer year) {
        super(name, surname, age, gender);
        this.university = university;
        this.department = department;
        this.year = year;
    }
}
