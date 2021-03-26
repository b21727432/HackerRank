package com.company;

import java.util.Comparator;

public class GPASorter implements Comparator<Student> {
    @Override
    public int compare(Student o1, Student o2) {
        return (int) (o1.CalculateGPA() - o2.CalculateGPA());
    }
}
