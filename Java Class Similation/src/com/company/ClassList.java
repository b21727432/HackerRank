package com.company;

import java.util.ArrayList;
import java.util.Collections;

public class ClassList {
    public ArrayList<Student> studentList;

    public ClassList() {
        this.studentList = new ArrayList<>();
    }

    public void Add(Student x){
        this.studentList.add(x);
    }

    public void PrintSortedList(int x){
        if(x == 0){
            Collections.sort(this.studentList, new GPASorter());
            pprint();
            Collections.sort(this.studentList, new GPASorter());
        }
        else if(x == 1){
            Collections.sort(this.studentList, new IDSorter());
            pprint();
            Collections.sort(this.studentList, new GPASorter());
        }
        else if(x == 2){
            Collections.sort(this.studentList, new NameSorter());
            pprint();
            Collections.sort(this.studentList, new GPASorter());
        }
        else if(x == 3){
            Collections.sort(this.studentList, new SurnameSorter());
            pprint();
            Collections.sort(this.studentList, new GPASorter());
        }

    }

    public void pprint(){
        int x;
        System.out.println("StudentID    Name    Surname    GPA");
        for(x = 0; x < this.studentList.size(); x++){
            System.out.println(this.studentList.get(x).getID() +"    "+ this.studentList.get(x).getName() +"    "+ this.studentList.get(x).getSurname() +"    "+ this.studentList.get(x).CalculateGPA());
        }
    }


}
